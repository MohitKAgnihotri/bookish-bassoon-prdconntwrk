/******** DO NOT EDIT THIS FILE ********/
#ifndef _JOB_H
#define _JOB_H
#include <stdbool.h>

/* 
 * Definition of struct job - for entry on a jobqueue and logging to a joblog.
 *
 * Type alias:
 * A struct job can also be referred to as job_t
 *
 * Fields:
 * id - the job id - which is locally unique to the producer that created
 *      the job (for valid jobs)
 * pid - the process id of the producer that created the job
 * 
 * For a valid job, the combination of { id, pid } should be globally unique.
 * That is, in a simulation where integrity is maintained, no two jobs should
 * have an id/pid combination the same.
 */
typedef struct job {
    int id;
    int pid;
} job_t;

/*
 * job_is_equal(job_t j1, job_t j2)
 * 
 * Tests whether the two jobs, j1 and j2, are equal. The jobs are considered 
 * equal if their id fields are equal and their pid fields are equal.
 *
 * Usage:
 *      job_t j1 = { 1, 2 };
 *      job_t j2 = { 1, 2 };
 *      job_t j3 = { 1, 3 };
 *      job_t j4 = { 2, 2 };
 *      job_t j5 = { 3, 4 };
 *      job_t j6 = { 3, 4 };
 *      
 *      job_is_equal(j1, j2); // true
 *      job_is_equal(j2, j3); // false
 *      job_is_equal(j2, j4); // false
 *      job_is_equal(j3, j4); // false
 *      job_is_equal(j5, j6); // true
 *
 * Parameters:
 * j1 - first job to compare
 * j2 - second job to compare
 *
 * Return:
 * True if j1 and j2 are equal (j1.id == j2.id and j1.pid == j2.pid), false
 *      otherwise
 */
bool job_is_equal(job_t j1, job_t j2);

#endif