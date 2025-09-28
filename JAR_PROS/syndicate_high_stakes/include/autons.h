#include "main.h"

class Drive;
class Intake;
class Pneumatics;

extern Drive chassis;
extern Intake intake;
extern Pneumatics pneumatics;

void default_constants();

void drive_test();
void turn_test();
void swing_test();
void full_test();

void redSWP();
void blueSWP();
void redElim();
void blueElim();
void skills();