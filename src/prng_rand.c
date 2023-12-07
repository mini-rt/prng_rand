#include "minirt_base.h"
#include "minirt_prng_rand.h"

#include <stdlib.h>

static void v_dispose(minirt_prng *self) {
	free(self);
}

static minirt_f v_random(minirt_prng *self) {
	(void)self;
	return rand() / (minirt_f)RAND_MAX;
}

static const minirt_prng_v v = { .dispose = v_dispose, .random = v_random };

minirt_prng *minirt_prng_rand(void) {
	minirt_prng *result = malloc(sizeof(minirt_prng));
	if (!result) return NULL;
	result->v = &v;
	return result;
}
