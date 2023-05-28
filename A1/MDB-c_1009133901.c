/*
 *  CSC A48 - Winter 2023 - Assignment 1 starter
 *
 *  (c) 2020-23 Francisco Estrada
 *  - No part of this code may be reproduced without written authorization
 *
 * This is the file where you will be doing most of your work. The
 * functionality you must provide for part 1 of the assignment is described
 * in the handout. Given in detail in the comments at the head of each
 * function below.
 *
 * Plan your work carefully, review the notes for Unit 3, and work carefully
 * to complete the functions in this file. You can bring
 * questions to your TAs or instructors during office hours. Please
 * remember:
 *
 * - You should not share any part of your solution in any form
 * - You should not post any assignment code on Piazza
 * - You should definitely *help* other understand any ideas and
 *   concepts regarding linked lists that you have already mastered,
 *   but being careful not to give away parts of the solution, or
 *   descriptions of how to implement functions below.
 * - If you are not sure whether you can or can not discuss some
 *   particular aspect of the work to be done, remember it's always
 *   safe to talk with your TAs.
 * - Obtaining external 'help' including being given code by an
 *   external party, or being tutored on how to solve
 *   the assignment constitutes an academic offense.
 *
 * All tasks to be completed by you are clearly labeled with a
 * ***** TO DO ****** comment block, which also gives you details
 * about what you have to implement. Look carefully and make sure
 * you don't miss a thing!
 *
 * NOTE: This file contains no main() function! you can not compile
 * it on its own to create an executable. It's meant to be used
 * together with Part1_driver.c - be sure to read that file carefully
 * to understand how to use the tests there - Any additional tests
 * you want to run on the code below should be added to Part1_driver.c
 *
 * Before you even get starter implementing, please complete the
 * student identification section below, and check that you are aware
 * of the policy on academic honesty and plagiarism.
 */

/* Student identification:
 *
 * Student Name (Last name, First name): Mayurathan, Ashwin
 * Student Number: 1009133901
 * UTORid: mayurat1
 * Your instructor's name is: Paco
 */

/* Academic Integrity Statement:
 *
 * I hereby certify that the work contained in this file is my own, and
 * that I have not received any parts of my solution from other sources
 * including my fellow students, external tutoring services, the internet,
 * or algorithm implementations found online.
 *
 * Sign here with your name: Ashwin Mayurathan
 *
 *
 */

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 1024

/* Compound data type declarations */
/***************************************************************************/
/******                         TO DO                               ********/
/****** In the space below, complete the definitions of the compound *******/
/****** data types that will be needed to implement the movie review *******/
/****** linked list. This includes the MovieReview type, and the     *******/
/****** ReviewNode. Details about the contents of these can be       *******/
/****** found in the assignment handout. Read them carefully!        *******/
/******                                                              *******/
/****** AFTER completing the basic linked list, complete the CDT     *******/
/****** required to implement a list for the movie's cast.           *******/
/***************************************************************************/

typedef struct castList_struct
{
    char name[MAX_STR_LEN];
    double salary;
    struct castList_struct *next;

} CastList;

typedef struct movieReview_struct
{
    char movie_title[MAX_STR_LEN];
    char movie_studio[MAX_STR_LEN];
    int year;
    double BO_total;
    int score;
    struct castList_struct *cast;


} MovieReview;

typedef struct reviewNode_struct
{
    MovieReview review;
    struct reviewNode_struct *next;

} ReviewNode;

typedef struct incomeList_struct
{
    char name[MAX_STR_LEN];
    double income;
    double num_movies;
    struct incomeList_struct *next;
} IncomeList;

void printNames(ReviewNode *movie)
{
// Prints out names of cast members for this movie
CastList *p;
if (movie==NULL||movie->review.cast==NULL) return;
p=movie->review.cast;
printf("The cast for this movie are:\n");
while (p!=NULL)
{
    printf("Cast Member: %s, Salary: %f\n",p->name,p->salary);
    p=p->next;
 }
}

ReviewNode *newMovieReviewNode()
{
    /*
     * This function allocates an empty ReviewNode, and initializes the
     * contents of the MovieReview for this node to reasonable (uninitialized) values.
     * The fields in the MovieReview should be set to:
     *  movie_title=""
     *  movie_studio=""
     *  year = -1
     *  BO_total = -1
     *  score = -1
     *  scoreList = NULL;
     *
     * The *next pointer for the new node MUST be set to NULL
     *
     * The function must return a pointer to the newly allocated and initialized
     * node. If something goes wrong, the function returns NULL
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *new_node=NULL;
    new_node = (ReviewNode *) calloc(1, sizeof(ReviewNode));
    strcpy(new_node->review.movie_title, "");
    strcpy(new_node->review.movie_studio, "");
    new_node->review.year = -1;
    new_node->review.BO_total = -1;
    new_node->review.score = -1;
    new_node->review.cast = NULL;
    new_node->next = NULL;
    return(new_node);
}

ReviewNode *findMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head)
{
    /*
     * This function searches through the linked list for a review that matches the input query.
     * The movie review must match the title, studio, and year provided in the
     * parameters for this function.
     *
     * If a review matching the query is found, this function returns the address of the node that
     * contains that review.
     *
     * If no such review is found, this function returns NULL
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *index = NULL;
    index = head;

    while (index){
        if (!(strcmp(index->review.movie_title, title))){
            if (!(strcmp(index->review.movie_studio, studio))){
                if (index->review.year == year){
                    return index;
                }
            }
        }
        index=index->next;
    }
    return NULL;

}

ReviewNode *insertMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function inserts a new movie review into the linked list.
     *
     * The function takes as input parameters the data neede to fill-in the review,
     * as well as apointer to the current head of the linked list.
     *
     * If head==NULL, then the list is still empty.
     *
     * The function inserts the new movie review *AT THE HEAD* of the linked list,
     * and returns the pointer to the new head node.
     *
     * The function MUST check that the movie is not already in the list before
     * inserting (there should be no duplicate entries). If a movie with matching
     * title, studio, and year is already in the list, nothing is inserted and the
     * function returns the current list head.
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    if ((findMovieReview(title, studio, year, head))){
        return head;
    }
    ReviewNode *new_entry = NULL;
    new_entry = (ReviewNode*)calloc(1, sizeof(ReviewNode));
    new_entry = newMovieReviewNode();
    strcpy(new_entry->review.movie_title, title);
    strcpy(new_entry->review.movie_studio, studio);
    new_entry->review.year = year;
    new_entry->review.BO_total = BO_total;
    new_entry->review.score = score;
    new_entry->next = head;
    return new_entry;
}

int countReviews(ReviewNode *head)
{
  /*
   * This function returns the number of reviews.
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    int count = 0;
    ReviewNode *index = NULL;
    index = head;

    while (index != NULL){
        count++;
        index = index->next;
    }

    return count;    // Remove this before you implement your solution
}

void updateMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function looks for a review matching the input query [title, studio, year].
     * If such a review is found, then the function updates the Box-office total, and the score.
     * If no such review is found, the function prints out
     * "Sorry, no such movie exists in the database"
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *index = NULL;
    index = findMovieReview(title, studio, year, head);
    if (index == NULL) printf("Sorry, no such movie exists in the database");
    else{
        index->review.BO_total = BO_total;
        index->review.score = score;
    }
}

ReviewNode *deleteMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN],int year, ReviewNode *head)
{
    /*
     * This function removes a review matching the input query from the database. If no such review can
     * be found, it does nothing.
     *
     * The function returns a pointer to the head of the linked list (which may have changed as a result
     * of the deletion process)
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *index = NULL;
    ReviewNode *index_aft = NULL;
    ReviewNode *remove = NULL;
    remove = findMovieReview(title, studio, year, head);
    index = head;
    if (remove){
        if (head == remove){
            index_aft = head->next;
            free(head);
            return index_aft;
        }
        ReviewNode *index_bef = NULL;
        while (index != remove){
            index_bef = index;
            index = index->next;
        }
        index_aft = remove->next;
        index_bef->next = index_aft;
        free(remove);
        }
    return head;      // Remove this before implementing your solution
}

float printMovieReviews(ReviewNode *head)
{
    /*
     * This function prints out all the reviews in the database, one after another.
     * Each field in the review is printed in a separate line, with *no additional text*
     * (that means, the only thing printed is the value of the corresponding field).
     *
     * Reviews are separated from each other by a line of
     * "*******************"

     * The function also computes and returns the Box-office total, for all the
     * movies that match the query.
     *
     * See the A1 handout for a sample of the output that should be produced
     * by this function
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *index = NULL;
    float sum = 0;
    index = head;
    while (index){
        printf("**********************\n");
        printf("%s\n",index->review.movie_title);
        printf("%s\n",index->review.movie_studio);
        printf("%d\n",index->review.year);
        printf("%f\n",index->review.BO_total);
        printf("%d\n",index->review.score);
        printf("**********************\n");
        sum += index->review.BO_total;
        index = index->next;
    }
    return sum;           // Remove this before you implement your solution
}

float queryReviewsByStudio(char studio[MAX_STR_LEN], ReviewNode *head)
{
    /*
     * This function looks for reviews whose studio matches the input query.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     *
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *index = NULL;
    float sum = 0;
    index = head;
    while (index){
        if (!strcmp(index->review.movie_studio, studio)){
            printf("**********************\n");
            printf("%s\n",index->review.movie_title);
            printf("%s\n",index->review.movie_studio);
            printf("%d\n",index->review.year);
            printf("%f\n",index->review.BO_total);
            printf("%d\n",index->review.score);
            printf("**********************\n");
            sum += index->review.BO_total;
        }
        index = index->next;
    }
    return sum;       // Remove this before you implement your solution
}

float queryReviewsByScore(int min_score, ReviewNode *head)
{
    /*
     * This function looks for reviews whose score is greater than, or equal to
     * the input 'min_score'.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     *
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *index = NULL;
    float sum = 0;
    index = head;
    while (index){
        if (index->review.score >= min_score){
            printf("**********************\n");
            printf("%s\n",index->review.movie_title);
            printf("%s\n",index->review.movie_studio);
            printf("%d\n",index->review.year);
            printf("%f\n",index->review.BO_total);
            printf("%d\n",index->review.score);
            printf("**********************\n");
            sum += index->review.BO_total;
        }
        index = index->next;
    }
    return sum;
}

ReviewNode *deleteReviewList(ReviewNode *head)
{
  /*
   * This function deletes the movie review database, releasing all the
   * memory allocated to the nodes in the linked list.
   *
   * Returns a NULL pointer so that the head of the list can be set to NULL
   * after deletion.
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *index = NULL;
    ReviewNode *index_aft = NULL;
    index = head;

    while(index){
        index_aft = index->next;
        free(index);
        index = index_aft;
    }
    return head;        // Remove this before you implement your solution
}

/* CRUNCHY SECTION! Do not work on the functions below until
 * your basic linked list is working properly and is fully tested!
 */

ReviewNode *sortReviewsByTitle(ReviewNode *head)
{
  /*
   * This function sorts the list of movie reviews in ascending order of movie
   * title. If duplicate movie titles exist, the order is arbitrary (i.e. you
   * can choose which one goes first).
   *
   * However you implement this function, it must return a pointer to the head
   * node of the sorted list.
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *index = NULL;
    ReviewNode *sort_index = NULL;
    ReviewNode *swap = NULL;
    char tit[MAX_STR_LEN];
    char stu[MAX_STR_LEN];
    int year;
    float BO;
    int score;
    CastList *cast = NULL;

    index = head;
    while (index){
        sort_index = index;
        swap = index;
        while(sort_index){
            if (strcmp(swap->review.movie_title, sort_index->review.movie_title)>0) swap = sort_index;
            sort_index = sort_index->next;
        }
        if (swap != index){
            strcpy(tit, index->review.movie_title);
            strcpy(stu, index->review.movie_studio);
            year = index->review.year;
            BO = index->review.BO_total;
            score = index->review.score;
            cast = index->review.cast;
            strcpy(index->review.movie_title, swap->review.movie_title);
            strcpy(index->review.movie_studio, swap->review.movie_studio);
            index->review.year = swap->review.year;
            index->review.BO_total = swap->review.BO_total;
            index->review.score = swap->review.score;
            index->review.cast = swap->review.cast;
            strcpy(swap->review.movie_title, tit);
            strcpy(swap->review.movie_studio, stu);
            swap->review.year = year;
            swap->review.BO_total = BO;
            swap->review.score = score;
            swap->review.cast = cast;
        }
        index = index->next;
    }


    return head;            // Remove this before you implement your solution
}
void copy_elements(CastList *paste, CastList *copy)
{
    strcpy(paste->name, copy->name);
    paste->salary = copy->salary;
    //paste->next = copy->next;
}
void insertCastMember(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head, char name[MAX_STR_LEN], float salary)
{
  /*
   * This function inserts the name of a cast member for the given movie into the
   * linked list of cast members. The new cast member must go to the end of the list.
   *
   * Duplicate names are allowed - this time!
   *
   * Notice the function receives the title, studio, and year for the movie, as
   * well as a pointer to the movie DB linked list. The function must find the
   * correct movie and if such a movie exists, add the cast member's name to its
   * cast list.
   *
   * If no such movie is found, this function does nothing.
   *
   * You're free to add helper functions to insert the cast member's name
   * into the cast list.
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *index = NULL;
    CastList *cast = NULL;
    CastList *new = NULL;
    CastList *temp = NULL;
    index = findMovieReview(title, studio, year, head);
    if (index){
        new = (CastList *) calloc(1, sizeof(CastList));
        strcpy(new->name, name);
        new->next = NULL;
        new->salary = salary;
        cast = index->review.cast;
        if(!cast) index->review.cast = new;
        else{
            temp = (CastList *) calloc(1, sizeof(CastList));
            strcpy(temp->name, " ");
            temp->salary = -1;
            temp->next = NULL;
            while (cast){
                if (cast->salary < new->salary)
                {
                    copy_elements(temp, cast);
                    copy_elements(cast, new);
                    copy_elements(new, temp);
                }
                cast = cast->next;
            }
            cast = index->review.cast;
            while(cast->next) cast = cast->next;
            cast->next = new;
        }
    }
}

IncomeList *create_income_index(char name[MAX_STR_LEN], double income, IncomeList *head)
{
    IncomeList *new = NULL;
    new = (IncomeList *) calloc(1, sizeof(IncomeList));
    strcpy(new->name, name);
    new->income = income;
    new->num_movies = 1;
    new->next = head;
    return new;
}
void whosTheStar(ReviewNode *head)
{
  /*
   *  This function goes through the movie database and determines who is
   * the cast members whose movies have the greatest average earnings.
   *
   * Earnings are defined as the box office total minus the salaries of all
   * cast members involved with the movie.
   *
   *  You're free to implement this function however you like, use any of
   * the code you wrote for other parts of the assignment, and write any
   * helper functions that you need. But:
   *
   *  You can not import extra libraries (no additional #include), and
   * all the implementation here should be your own.
   *
   *  The function simply       s out:
   *
   *  Name of cast member
   *  Average movie earnings (as a floating point number)
   *
   *  For the cast member whose movies make the greatest average earnings
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    //Initialize
    ReviewNode *p = NULL;
    ReviewNode *i = NULL;
    CastList *j = NULL;
    char actor[MAX_STR_LEN];

    char highest_name[MAX_STR_LEN];
    float highest_avg =0;
    strcpy(highest_name, "");

    float earnings = 0;
    int movie_count = 0;
    float avg_earnings =0;

    for (p =head; p != NULL; p = p->next)
    {
        j = p -> review.cast;

        while ( j!= NULL)
        {
            strcpy(actor, j->name);

            for (i =head; i != NULL; i = i->next)
            {
                if (is_cast(i, actor) == 1)
                {
                    earnings = earnings + movie_earnings(i);
                    movie_count = movie_count +1;
                }

            }

            avg_earnings = earnings/movie_count;

            if (avg_earnings>= highest_avg)
            {
                highest_avg = avg_earnings;
                strcpy(highest_name, actor);
            }

            earnings =0;
            movie_count =0;
            avg_earnings =0;

            j = j ->next;
        }
    }

    if (strcmp(highest_name, "") != 0)
    {
        printf("%s\n%f\n", highest_name, highest_avg);
    }
}
