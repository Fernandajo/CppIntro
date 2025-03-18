#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"

// int main() {
//     std::cout << "--- Correct Inheritance ---" << std::endl;
//     {
// 	const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
    
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound();
//     j->makeSound();
//     meta->makeSound();
    
//     delete meta;
//     delete j;
//     delete i;
// 	}
//     std::cout << "\n--- Wrong Inheritance ---" << std::endl;
//     const WrongAnimal* wrongMeta = new WrongAnimal();
//     const WrongAnimal* wrongCat = new WrongCat();
    
//     std::cout << wrongCat->getType() << " " << std::endl;
//     wrongCat->makeSound(); // Will call WrongAnimal's makeSound due to missing virtual keyword
//     wrongMeta->makeSound();
    
//     delete wrongMeta;
//     delete wrongCat;

//     return 0;
// }


int main()
{
	{
		std::cout << "\033[1;35m=== Default Test ===\033[0m" << std::endl;

		std::cout << "\033[1;32m=== Constructors ===\033[0m" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << "\033[1;34m=== Checking Types ===\033[0m" << std::endl;
		std::cout << "Expected: Dog, Actual: "<< j->getType() << std::endl;
		std::cout << "Expected: Cat, Actual: "<< i->getType() << std::endl;
		std::cout << "Expected: Animal, Actual: " << meta->getType() << std::endl;
		std::cout << "\033[1;34m=== Making Sounds ===\033[0m" << std::endl;
		std::cout << "Dog Says: ";
		j->makeSound();
		std::cout << "Cat Says: ";
		i->makeSound();
		std::cout << "Animal Says: ";
		meta->makeSound();

		std::cout << "\033[1;31m=== Destructors Called ===\033[0m" << std::endl;
		delete meta;
		delete j;
		delete i;

		std::cout << "\033[1;35m=== Test Concluded ===\033[0m" << std::endl;
	}

	{
		// Test with WrongAnimal and WrongCat (Demonstrating the Polymorphism Issue)
		std::cout << "\033[1;35m\n=== WrongAnimal Test ===\033[0m" << std::endl;

		std::cout << "\033[1;32m=== Constructors ===\033[0m" << std::endl;
		const WrongAnimal* wrongMeta = new WrongAnimal();
		const WrongAnimal* wrongCat = new WrongCat();
		const WrongCat* actualWrongCat = new WrongCat();

		std::cout << "\033[1;34m=== Checking Types ===\033[0m" << std::endl;
		std::cout << "Expected: WrongAnimal, Actual: "<< wrongMeta->getType() << std::endl;
		std::cout << "Expected: WrongCat, Actual: "<< wrongCat->getType() << std::endl;
		std::cout << "Expected: WrongCat, Actual: "<< actualWrongCat->getType() << std::endl;

		std::cout << "\033[1;34m=== Making Sounds ===\033[0m" << std::endl;
		std::cout << "WrongAnimal Says: ";
		wrongMeta->makeSound(); // Expected: "Random WrongAnimal sound!"
		std::cout << "WrongCat (Stored as WrongAnimal*) Says: ";
		wrongCat->makeSound(); // Expected: "Random WrongAnimal sound!" (Polymorphism is broken)
		std::cout << "WrongCat (Stored as WrongCat*) Says: ";
		actualWrongCat->makeSound(); // Expected: "WrongMeow (WrongCat sound)" (Direct call works)

		std::cout << "\033[1;31m=== Destructors Called ===\033[0m" << std::endl;
		delete wrongMeta;
		delete wrongCat;
		delete actualWrongCat;

		std::cout << "\033[1;35m=== WrongAnimal Test Concluded ===\033[0m\n" << std::endl;
	}
	{
		std::cout << "\033[1;35m\n=== Extra Tests: Copy and Assignment ===\033[0m" << std::endl;

		std::cout << "\033[1;32m=== Creating Original Objects ===\033[0m" << std::endl;
		Dog originalDog;
		Cat originalCat;
		WrongCat originalWrongCat;

		std::cout << "\033[1;32m=== Copy Construction ===\033[0m" << std::endl;
		Dog copiedDog(originalDog);
		Cat copiedCat(originalCat);
		WrongCat copiedWrongCat(originalWrongCat);

		std::cout << "\033[1;32m=== Assignment Operator ===\033[0m" << std::endl;
		Dog assignedDog;
		assignedDog = copiedDog;
		Cat assignedCat;
		assignedCat = copiedCat;
		WrongCat assignedWrongCat;
		assignedWrongCat = copiedWrongCat;
		std::cout << "\033[1;31m=== Destructors ===\033[0m" << std::endl;
	}
	std::cout << "\033[1;35m=== Extra Tests Concluded ===\033[0m\n" << std::endl;
	return 0;
}