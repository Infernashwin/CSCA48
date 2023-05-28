/*
 * CSC A48 - Assignment 3 driver
 *
 * This driver is *very* different from the ones for A1 and A2.
 *
 * For the previous 2 assignments, and through the exercises
 * you have solved so far, we have been helping you develop and
 * improve your skills for testing code and verything it is
 * *correct*.
 *
 * So, this driver only does the basic functionality of
 * calling the functions that set-up a graph, and shows you
 * how to call the functions that you have to implement.
 *
 * Defining the tests you have to run on your code, and
 * determining whether the code is correct, is up to you.
 *
 * *You will NOT submit this file* - but you obviously want
 * to make sure you run sufficient and thorough testing of
 * all components of your A3 solution to avoid any problems
 * when we auto-mark it.
 *
 * Suggestions: Test for *correctness*, not output. As we
 * have explained before - you can write code that produces
 * the right output and still is completely wrong in terms of
 * what it does to solve a problem.
 *
 * So, think carefully about the correctness aspect of your
 * solution, see the post on Piazza on how to test your
 * code (it's old by now, but pinned), and remember your
 * notes for Unit 5 - the section on how to debug recursive
 * code.
 *
 * (c) 2019 - F. Estrada, M. Ahmadzadeh
 */

#include<stdio.h>
#include<stdlib.h>
#include"ingredient_graph_1009133901.c"

int main()
{
   /*
    * Just a quick demo of how to set up the graph and call
    * the functions you are supposed to implement
    */

   intNode *head=NULL;
   char recipe[10][MAX_STR_LEN]={"fresh breadcrumbs",
				 "artichoke hearts",
				 "quinoa",
				 "",
				 "",
				 "",
				 "",
				 "",
				 "",
				 ""};

   char recipe_two[10][MAX_STR_LEN]={"fresh breadcrumbs",
				 "",
				 "",
				 "",
				 "",
				 "",
				 "",
				 "",
				 "",
				 ""};

   char recipe_three[10][MAX_STR_LEN]={"medium shrimp",
				 "turkey",
				 "quinoa",
				 "",
				 "",
				 "",
				 "",
				 "",
				 "",
				 ""};

   char recipe_four[10][MAX_STR_LEN]={"medium shrimp",
				 "turkey",
				 "artichoke hearts",
				 "",
				 "",
				 "",
				 "",
				 "",
				 "",
				 ""};

   // Load the ingredients graph - you control which size
   // you want by commenting/uncommenting the corresponding
   // #define at the top of 'ingredient_graph.c'
   load_ingredients();
   printf("------- The available ingredients should appear above this line -------\n");
   // Call related ingredients
   printf("\n ****** Related ingredients for quinoa:\n");
   related_ingredients("quinoa");  // Make sure this
				   // ingredient exists

   printf("\n ****** Related to 'quinoa' k-dist, k=1 - Updtaed\n");
   head=related_k_dist(head,"quinoa",1,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related to 'quinoa' k-dist, k=2 - Updated\n");
   head=related_k_dist(head,"quinoa",2,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related to 'artichoke hearts' k-dist, k=1 - Updated\n");
   head=related_k_dist(head,"artichoke hearts",1,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related to 'tomato juice' k-dist, k=1 - Updated\n");
   head=related_k_dist(head,"tomato juice",1,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related to 'tomato juice' k-dist, k=2 - Updated\n");
   head=related_k_dist(head,"tomato juice",2,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related with restrictions, 'quinoa', 'artichoke hearts', k_source=1, k_dest=1 - Updated;\n");
   head=related_with_restrictions("quinoa","artichoke hearts",1,1);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related with restrictions, 'quinoa', 'tomato juice', k_source=2, k_dest=1 - Updated;\n");
   head=related_with_restrictions("quinoa","tomato juice",2,1);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related with restrictions, 'quinoa', 'tomato juice', k_source=2, k_dest=2 - Updated;\n");
   head=related_with_restrictions("quinoa","tomato juice",2,2);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** substituting ingredient 'quinoa' in recipe\n");
   substitute_ingredient(recipe,"quinoa");
   for (int i=0; i<10; i++)
     if (strlen(recipe[i])>0) printf("%s\n",recipe[i]);

   /* The OUTPUT of my solution to this assignment for the sample calls above is:

 ****** Related ingredients for quinoa:
artichoke hearts
sunflower seeds

 ****** Related to 'quinoa' k-dist, k=1 - Updtaed
sunflower seeds
artichoke hearts

 ****** Related to 'quinoa' k-dist, k=2 - Updated
gruyere cheese
turkey
medium shrimp
quinoa
soymilk
sunflower seeds
artichoke hearts

 ****** Related to 'artichoke hearts' k-dist, k=1 - Updated
quinoa
gruyere cheese
turkey
medium shrimp

 ****** Related to 'tomato juice' k-dist, k=1 - Updated
fresh breadcrumbs
prepared horseradish

 ****** Related to 'tomato juice' k-dist, k=2 - Updated
medium shrimp
gruyere cheese
tomato juice
fresh breadcrumbs
prepared horseradish

 ****** Related with restrictions, 'quinoa', 'artichoke hearts', k_source=1, k_dest=1 - Updated;
sunflower seeds

 ****** Related with restrictions, 'quinoa', 'tomato juice', k_source=2, k_dest=1 - Updated;
artichoke hearts
sunflower seeds
soymilk
quinoa
medium shrimp
turkey
gruyere cheese

 ****** Related with restrictions, 'quinoa', 'tomato juice', k_source=2, k_dest=2 - Updated;
artichoke hearts
sunflower seeds
soymilk
quinoa
turkey

 ****** substituting ingredient 'quinoa' in recipe
fresh breadcrumbs
artichoke hearts
gruyere cheese

****** substituting ingredient 'fb' in recipe with only fb
medium shrimp

 ****** Related to 'fb' k-dist, k=0 - Updtaed

 ****** Related to 'fresh breadcrumbs' k-dist, k=1 - Updated
gruyere cheese
tomato juice

 ****** Related to 'fresh breadcrumbs' k-dist, k=2 - Updtaed
artichoke hearts
gruyere cheese
fresh breadcrumbs
prepared horseradish
tomato juice

 ****** Related to 'fresh breadcrumbs' k-dist, k=3 - Updated
quinoa
turkey
artichoke hearts
gruyere cheese
fresh breadcrumbs
medium shrimp
prepared horseradish
tomato juice

 ****** Related to 'fresh breadcrumbs' k-dist, k=4 - Updated
sunflower seeds
quinoa
turkey
gruyere cheese
fresh breadcrumbs
artichoke hearts
medium shrimp
prepared horseradish
tomato juice

 ****** Related to 'fresh breadcrumbs' k-dist, k=5 - Updated
soymilk
sunflower seeds
fresh breadcrumbs
quinoa
gruyere cheese
turkey
artichoke hearts
medium shrimp
prepared horseradish
tomato juice

 ****** Related to 'tomato juice' k-dist, k=3 - Updated
gruyere cheese
fresh breadcrumbs
tomato juice
artichoke hearts
medium shrimp
prepared horseradish

 ****** Related to 'tomato juice' k-dist, k=4 - Updated
fresh breadcrumbs
quinoa
gruyere cheese
turkey
artichoke hearts
tomato juice
medium shrimp
prepared horseradish

 ****** Related to 'tomato juice' k-dist, k=5 - Updated
sunflower seeds
quinoa
gruyere cheese
turkey
fresh breadcrumbs
tomato juice
artichoke hearts
medium shrimp
prepared horseradish

 ****** Related with restrictions, 'fresh breadcrumbs', 'artichoke hearts', k_source=3, k_dest=0 - Updated;
tomato juice
prepared horseradish
medium shrimp
fresh breadcrumbs
gruyere cheese
turkey
quinoa

 ****** Related with restrictions, 'fresh breadcrumbs', 'artichoke hearts', k_source=3, k_dest=1 - Updated;
tomato juice
prepared horseradish
fresh breadcrumbs

 ****** Related with restrictions, 'fresh breadcrumbs', 'tomato juice', k_source=2, k_dest=1 - Updated;
gruyere cheese
artichoke hearts

 ****** Related with restrictions, 'fresh breadcrumbs', 'tomato juice', k_source=4, k_dest=2 - Updated;
artichoke hearts
turkey
quinoa
sunflower seeds

 ****** Related with restrictions, 'fresh breadcrumbs', 'tomato juice', k_source=5, k_dest=3 - Updated;
turkey
quinoa
sunflower seeds
soymilk

 ****** substituting ingredient 'quinoa' in recipe three, should become artichoke heart
medium shrimp
turkey
artichoke hearts

 ****** substituting ingredient 'artichoke heart' in recipe four, should become prepared horseradish
medium shrimp
turkey
prepared horseradish

   You can use that as a reference, but BEWARE the fact that though I am confident my
   solution is correct *I have not had the time to thoroughly test it*
   (you should know by now what that means)

   */

   // Insert ALL of your tests below this line, make sure you test your
   // code thoroughly.
   // Verify your code's work by checking *on paper* for lists of
   // ingredients your tests ask for!
   // Time to practice those testing skills!

   printf("\n ****** substituting ingredient 'fb' in recipe with only fb\n");
   substitute_ingredient(recipe_two,"fresh breadcrumbs");
   for (int i=0; i<10; i++)
     if (strlen(recipe_two[i])>0) printf("%s\n",recipe_two[i]);

   printf("\n ****** Related to 'fb' k-dist, k=0 - Updtaed\n");
   head=related_k_dist(head,"fresh breadcrumbs",0,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related to 'fresh breadcrumbs' k-dist, k=1 - Updated\n");
   head=related_k_dist(head,"fresh breadcrumbs",1,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related to 'fresh breadcrumbs' k-dist, k=2 - Updtaed\n");
   head=related_k_dist(head,"fresh breadcrumbs",2,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related to 'fresh breadcrumbs' k-dist, k=3 - Updated\n");
   head=related_k_dist(head,"fresh breadcrumbs",3,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related to 'fresh breadcrumbs' k-dist, k=4 - Updated\n");
   head=related_k_dist(head,"fresh breadcrumbs",4,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related to 'fresh breadcrumbs' k-dist, k=5 - Updated\n");
   head=related_k_dist(head,"fresh breadcrumbs",5,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related to 'tomato juice' k-dist, k=3 - Updated\n");
   head=related_k_dist(head,"tomato juice",3,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related to 'tomato juice' k-dist, k=4 - Updated\n");
   head=related_k_dist(head,"tomato juice",4,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related to 'tomato juice' k-dist, k=5 - Updated\n");
   head=related_k_dist(head,"tomato juice",5,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related with restrictions, 'fresh breadcrumbs', 'artichoke hearts', k_source=3, k_dest=0 - Updated;\n");
   head=related_with_restrictions("fresh breadcrumbs","artichoke hearts",3,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related with restrictions, 'fresh breadcrumbs', 'artichoke hearts', k_source=3, k_dest=1 - Updated;\n");
   head=related_with_restrictions("fresh breadcrumbs","artichoke hearts",3,1);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related with restrictions, 'fresh breadcrumbs', 'tomato juice', k_source=2, k_dest=1 - Updated;\n");
   head=related_with_restrictions("fresh breadcrumbs","tomato juice",2,1);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related with restrictions, 'fresh breadcrumbs', 'tomato juice', k_source=4, k_dest=2 - Updated;\n");
   head=related_with_restrictions("fresh breadcrumbs","tomato juice",4,2);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related with restrictions, 'fresh breadcrumbs', 'tomato juice', k_source=5, k_dest=3 - Updated;\n");
   head=related_with_restrictions("fresh breadcrumbs","tomato juice",5,3);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** substituting ingredient 'quinoa' in recipe three, should become artichoke heart\n");
   substitute_ingredient(recipe_three,"quinoa");
   for (int i=0; i<10; i++)
     if (strlen(recipe_three[i])>0) printf("%s\n",recipe_three[i]);

   printf("\n ****** substituting ingredient 'artichoke heart' in recipe four, should become prepared horseradish\n");
   substitute_ingredient(recipe_four,"artichoke hearts");
   for (int i=0; i<10; i++)
     if (strlen(recipe_four[i])>0) printf("%s\n",recipe_four[i]);
  return 0;
}
