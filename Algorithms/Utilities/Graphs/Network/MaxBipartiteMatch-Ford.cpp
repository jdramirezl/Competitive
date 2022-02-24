/*
Problem example:
There are M students and N courses. 
Each student has a set of jobs that they're interested in.
Each course only accepts one student and one student only accepts one course.
Find a group of matches that maximize the number of students in courses.

We convert the groups into a flow network

We create a source and sink
We connect the src to the first group (students)
Then the first group to the second (courses)
Then the second group to the sink

The capacities between the first and second group is defined by the problem
(In this case capacity would be 1, as a course only accepts one student)
As well as for the rest of the edges
*/

/*
We use Ford Fulkerson
T.C: O(ve)
*/

#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vi>
#define vec(type) vector<type>
using namespace std;

// M is number of applicants
// and N is number of jobs
#define M 6
#define N 6

// True if matching for vertex 'curr' is possible
bool bpm(vvi &bpGraph, int curr, vec(bool) &seen, vi &matchR){
    // Try every job
    for (int job = 0; job < N; job++){
        // If applicant is interested in a job, and the job isn't visited
        if (bpGraph[curr][job] && !seen[job]){
            seen[job] = true;

            /* If job isnt assigned -1,
            Or job is assigned, but the previously assigned applicant
            Has alternative job */
            if (matchR[job] == -1 || bpm(bpGraph, matchR[job], seen, matchR)){
                matchR[job] = curr;
                return true;
            }
        }
    }
    return false;
}

// bpGraph: N*M matrix where graph[i][j] == 1 marks an edge
int maxBPM(vvi &bpGraph){
    // matchR[i]: tracks what applicant was assigned to job 'i'
    vi matchR(N, -1);

    // Count of jobs assigned to applicants
    int result = 0;
    for (int curr = 0; curr < M; curr++){
        // Mark all jobs as not seen for next applicant.
        vec(bool) seen(N, 0);

        // Find if the applicant 'u' can get a job
        if (bpm(bpGraph, curr, seen, matchR)) result++;
    }

    return result;
}