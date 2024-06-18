#include "population.h"
#include "creature.h"
#include "event.h"

#include <stdlib.h>

// Define NPOP to access the number of creatures globally
extern int NPOP;

// step
int step;

//creature array
Creature* creature_array;

// Initialize the population of creatures
int population_init(int numCreatures) {
    creature_array = malloc(numCreatures * sizeof(Creature));
    if (creature_array == NULL) {
        return 0; // Allocation failed
    }
    
    for (int i = 0; i < numCreatures; i++) {
        creature_init(&creature_array[i]);
    }
    return 1;
}

// Update the state of the population based on the play mode and input
void population_update() {
    for (int i = 0; i < NPOP; i++) {
        creature_directional_rotate(&creature_array[i], step);
        creature_move(&creature_array[i], step);
    }
}

// Draw the population of creatures
void population_draw(SDL_Renderer* renderer) {
    for (int i = 0; i < NPOP; i++) {
        creature_draw(&creature_array[i], renderer);
    }
}

// Free the memory allocated for the population
void population_free() {
    for (int i = 0; i < NPOP; i++) {
        creature_free(&creature_array[i]);
    }
    free(creature_array);
    creature_array = NULL;
}