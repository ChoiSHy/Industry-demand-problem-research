#include <stdio.h>

extern void get_school_position(int , int* , int* );
extern void get_student_position(int , int* , int* );
extern void set_student_school(int , int);

typedef struct School {
	int count = 0;
	int students[10000][2];
}school;

school schools[3];
int kmil = 10000 * 10000;
int next_idx = 0;

int get_distance(int student, int school) {
	int std_x, std_y;
	int sch_x, sch_y;
	int* px = &std_x, *py = &std_y;
	int dx = 0,dy = 0;

	get_student_position(student, px, py);
	px = &sch_x, py = &sch_y;
	get_school_position(school, px, py);

	dx = std_x - sch_x;
	dy = std_y - sch_y;

	return (dx * dx) + (dy * dy);
}
int get_min(int* dis) {
	int min, min_idx;
	min = dis[0];
	min_idx = 0;

	if (dis[1] < min) {
		min = dis[1];
		min_idx = 1;
	}
	if (dis[2] < min) {
		min_idx = 2;
	}
	return min_idx;
}
int search(int student, int distance, int school_idx) {
	int count = schools[school_idx].count;

	for (int i = 0; i < count; i++) {
		if (schools[school_idx].students[i][1] > distance) 
		{
			next_idx = schools[school_idx].students[i][0];
			schools[school_idx].students[i][0] = student;
			schools[school_idx].students[i][1] = distance;
			return 0;
		}
	}
	if (count >= 3500 && distance < kmil) {
		next_idx = 0;
		return -1;
	}
	else {
		printf("%d\t%d\t%d\n", student, school_idx, distance);
		schools[school_idx].students[count][0] = student;
		schools[school_idx].students[count][1] = distance;
		schools[school_idx].count++;

		next_idx = 0;
		
		return 0;
	}
}
void match_school(int student) {
	//printf("--->\t%d\n", student);
	int distance[3];
	int idx;
	int ret=-1;
	for (int i = 0; i < 3; i++) 
		distance[i] = get_distance(student, i);
	

	while (ret==-1) {
		idx = get_min(distance);

		ret = search(student, distance[idx], idx);

		if (ret == -1) {
			distance[idx] += kmil;
		}
	}

}

void run_contest() {
	for (int i = 0; i < 3500; i++) {
		match_school(i);
		while (next_idx != 0)			
			match_school(next_idx);
	}

	for (int i = 0; i < 3; i++) {
		printf("[%d]: %d\n", i, schools[i].count);
		for (int j = 0; j < schools[i].count; j++) {
			set_student_school(schools[i].students[j][0], i);
		}
	}
}