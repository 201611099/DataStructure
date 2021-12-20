#ifndef SIMULATION_H
# define SIMULATION_H

# include "./circular_queue.h"

# define NUM	5 //고객 수

typedef t_data	SimCustomer;

void	customer_init(SimCustomer *cust, int arrTime, int svTime); //고객 정보 초기화
void	set_arrival(ArrayQueue *cus, ArrayQueue *wait, int time); //고객 도착 정보 세팅
void	service(ArrayQueue *wait, int time); // 서비스 시작 및 종료
void	service_end(ArrayQueue *cus, ArrayQueue *wait, int time); //종료 이후
double average_waiting(ArrayQueue *cus); //평균 대기 시간
void	display_customer(ArrayQueue *cus); //대기 큐 출력

#endif