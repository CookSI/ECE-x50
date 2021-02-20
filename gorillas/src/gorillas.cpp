#include <iostream>
#include <cmath>

//Function and variable definitions
#ifndef MARMOSET_TESTING
int main();
#endif


double horizontal_velocity(double launch_velocity, double launch_angle);
double vertical_velocity(double launch_velocity, double launch_angle);
double gravity();
double computed_range(double launch_velocity, double launch_angle, double height);




double horizontal_velocity(double launch_velocity, double launch_angle){
	double Vx = launch_velocity * cos(M_PI*launch_angle/180);
	return Vx;
}
double vertical_velocity(double launch_velocity, double launch_angle){
	double Vy = launch_velocity * sin(M_PI*launch_angle/180);
	return Vy;
}
double gravity(){
	return 9.80665;
}
double computed_range(double launch_velocity, double launch_angle, double height){
	double Vy = launch_velocity * sin(M_PI*launch_angle/180);
	double Vx = launch_velocity * cos(M_PI*launch_angle/180);
	double distance = ((Vy*Vx)+ Vx*sqrt(Vy*Vy + 2*gravity()*height))/gravity();
	return distance;
}

#ifndef MARMOSET_TESTING

int main(){

	std::cout << "The range the banana reaches for the launch angle of 10 degrees is " << computed_range(600,10,10) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 20 degrees is " << computed_range(600,20,10) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 25.5 degrees is " << computed_range(600,25.5,10) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 30 degrees is " << computed_range(600,30,10) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 40 degrees is " << computed_range(600,40,10) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 50 degrees is " << computed_range(600,50,10) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 55.5 degrees is " << computed_range(600,55.5,10) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 60 degrees is " << computed_range(600,60,10) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 70 degrees is " << computed_range(600,70,10) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 75.5 degrees is " << computed_range(600,75.5,10) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 80 degrees is " << computed_range(600,80,10) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 90 degrees is " << computed_range(600,90,10) << std :: endl;
	/*
	std::cout << "The range the banana reaches for the launch angle of 10 degrees is " << computed_range(600,10,0) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 20 degrees is " << computed_range(600,20,0) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 25.5 degrees is " << computed_range(600,25.5,0) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 30 degrees is " << computed_range(600,30,0) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 40 degrees is " << computed_range(600,40,0) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 50 degrees is " << computed_range(600,50,0) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 55.5 degrees is " << computed_range(600,55.5,0) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 60 degrees is " << computed_range(600,60,0) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 70 degrees is " << computed_range(600,70,0) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 75.5 degrees is " << computed_range(600,75.5,0) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 80 degrees is " << computed_range(600,80,0) << std :: endl;
	std::cout << "The range the banana reaches for the launch angle of 90 degrees is " << computed_range(600,90,0) << std :: endl;
	// The range the banana reaches for the launch angle of 50 degrees is 36157.7
	*/
	return 0;
}
#endif
