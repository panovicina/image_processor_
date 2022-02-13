#pragma once

#include <map>
#include <set>
#include <string>
#include <vector>

void DelStudents(const StudentName& student_name) {
    if (score_table[student_name].empty()) {
        score_table.erase(student_name);
    }
}
void DelFromTable(const StudentName& student_name, const TaskName& task_name) {
    score_table[student_name].erase(task_name);
    DelStudents(student_name);
}
void AddToTable(const StudentName& student_name, const TaskName& task_name) {
    score_table[student_name].insert(task_name);
}

class Scorer {
public:
    ScoreTable score_table;
    void OnCheckFailed(const StudentName& student_name, const TaskName& task_name) {
        DelFromTable(student_name, task_name);
    }
    void OnCheckSuccess(const StudentName& student_name, const TaskName& task_name) {
        AddToTable(student_name, task_name);
    }
    void OnMergeRequestOpen(const StudentName& student_name, const TaskName& task_name) {
        DelFromTable(student_name, task_name);
    }
    void OnMergeRequestClosed(const StudentName& student_name, const TaskName& task_name) {
        AddToTable(student_name, task_name);
    }
    void Reset() {
        score_table.clear();
    }
    ScoreTable GetScoreTable() const {
        return score_table;
    }
}