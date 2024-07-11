#include "population.h"
#include "creature.h"
#include "event.h"

#include <stdlib.h>

// Define NPOP to access the number of creatures globally
extern int NPOP;


//creature array
Creature* creature_array;

// Initialize the population of creatures
int population_init() {
    creature_array = malloc(NPOP * sizeof(Creature));
    if (creature_array == NULL) {
        return EXIT_FAILURE; // Allocation failed
    }
    
    for (int i = 0; i < NPOP; i++) {
        creature_init(&creature_array[i]);
    }
    return EXIT_SUCCESS;
}

// Update the state of the population based on the play mode and input
void population_update(int simulation_step) {
    for (int i = 0; i < NPOP; i++) {
        creature_directional_rotate(&creature_array[i], simulation_step);
        creature_move(&creature_array[i]);
    }
}

// Draw the population of creatures
void population_draw() {
    for (int i = 0; i < NPOP; i++) {
        creature_draw(&creature_array[i]);
    }
}

// Free the memory allocated for the population
void population_cleanup() {
    for (int i = 0; i < NPOP; i++) {
        creature_free(&creature_array[i]);
    }
    free(creature_array);
    creature_array = NULL;
}