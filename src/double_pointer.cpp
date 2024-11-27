#include <iostream>
using namespace std;

float sum(float arr[], int size) {
    float result = 0.f;

    for (int i = 0; i < size; i++) {
        result += arr[i];
    }
    return result;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

int main(void){
    int course_amount;
    cin >> course_amount;

    int **course = new int *[course_amount];
    float mean_course[course_amount];
    int sizes[course_amount];
    for (int i = 0; i < course_amount; i++){
        int amount_grades;
        cin >> amount_grades;

        course[i] = new int[amount_grades];
        sizes[i] = amount_grades;
        mean_course[i] = 0;

        for (int j = 0; j < amount_grades; j++){
            int received;
            cin >> received;

            course[i][j] = received;
            mean_course[i] += received;
        }

        cout << mean_course[i] << '\n';
        mean_course[i] /= (float)amount_grades;
    }
    

    cout.precision(3);
    for (int i = 0; i < course_amount; i++){
        cout << "Course " << i <<": final " << mean_course[i] << " grades: ";
        printArray(course[i], sizes[i]);
    }
    cout << "Overall final: " << sum(mean_course, course_amount)/(float)course_amount << endl;

    for (int i = 0; i < course_amount; i++){
        delete [] course[i];
    }
    delete[] course;
    delete[] sizes;
    delete[] mean_course;
    return 0;
}
