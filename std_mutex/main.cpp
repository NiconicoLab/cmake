#include <stdio.h>
#include <thread>
#include <mutex>

#define WRITE_LOOP_NUM 2000
#define MUTEX_ENABLE

std::mutex m;
int num;

int array[WRITE_LOOP_NUM+1];
int cnt;

void update_num(int i)
{
	int tmp;
#ifdef MUTEX_ENABLE // enable mutex for num
	m.lock();
	tmp = (++num);
	array[cnt++] = tmp;
	m.unlock();
#else // without mutex for num
	tmp = (++num);
	m.lock();
	array[cnt++] = tmp;
	m.unlock();
#endif
}

void thread1()
{
	for(int i = 0; i < WRITE_LOOP_NUM; i++)
	{
		update_num(1);
	}
}

void thread2()
{
	for(int i = 0; i < WRITE_LOOP_NUM; i++)
	{
		update_num(2);
	}
}

int main (int argc, char *argv[])
{
	num = 0;
	cnt = 0;
	
	std::thread t1(thread1);
	std::thread t2(thread2);
	t1.join();
	t2.join();

	for(int i = 0; i < WRITE_LOOP_NUM*2; i++)
	{
		printf("%d : %d\n", i, array[i]);
	}
	
	return 0;
}
