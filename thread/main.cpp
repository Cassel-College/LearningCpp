#include <iostream>
#include <thread>
#include <mutex>

void work1(int& sum, std::mutex& mylock) {
	for (int i = 1; i < 5000; i++) {
		std::lock_guard<std::mutex> mylock_guard(mylock);
		sum += i;
	}
}

// void work2(int& sum, std::mutex& mylock) {
// 	for (int i = 5000; i <= 10000; i++) {
// 		std::lock_guard<std::mutex> mylock_guard(mylock);
// 		sum += i;
// 	}
// }


// void work1(int& sum, std::mutex& mylock) {
// 	for (int i = 1; i < 5000; i++) {
// 		mylock.lock();
// 		sum += i;
// 		mylock.unlock();
// 	}
// }

void work2(int& sum, std::mutex& mylock) {
	for (int i = 5000; i <= 10000; i++) {
		mylock.lock();
		sum += i;
		mylock.unlock();
	}
}


int fun() {
	int sum = 0;
	for (int i = 1; i <= 10000; i++) {
		sum += i;
	}
	return sum;
}

int main()
{
	std::mutex mylock;
	int ans = 0;
	std::thread t1(work1, std::ref(ans), std::ref(mylock));
	std::thread t2(work2, std::ref(ans), std::ref(mylock));
	t1.join();
	t2.join();
	std::cout << "sum1 : " << ans << std::endl;
	std::cout << "sum2 : " << fun() << std::endl;
	return 0;
}