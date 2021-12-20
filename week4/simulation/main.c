#include "./simulation.h"

int	main(void)
{
	ArrayQueue	*cus;
	ArrayQueue	*wait;
	SimCustomer	customer;
	int			t = 0;

	cus = createArrayQueue(NUM);
	wait = createArrayQueue(NUM);

	customer_init(&customer, 0, 3);
	enqueue(cus, customer);
	customer_init(&customer, 2, 2);
	enqueue(cus, customer);
	customer_init(&customer, 4, 1);
	enqueue(cus, customer);
	customer_init(&customer, 6, 1);
	enqueue(cus, customer);
	customer_init(&customer, 8, 3);
	enqueue(cus, customer);

      printf("\n\x1b[31m===== when t = %d, customer_queue =====\n\x1b[0m", t);
    display_customer(cus);

    printf("\x1b[34m===== when t = %d, waiting_queue =====\n\x1b[0m", t);
    display_customer(wait);
	while (is_empty(wait) == FALSE || peek(cus).status != end)
	{
	// 	if (is_empty(wait) == TRUE && peek(cus).status == end)
	// 		break ;
		set_arrival(cus, wait, t);
		service(wait, t);
		service_end(cus, wait, t);
    printf("\n\x1b[31m===== when t = %d, customer_queue =====\n\x1b[0m", t);
    display_customer(cus);
    printf("\x1b[34m===== when t = %d, waiting_queue =====\n\x1b[0m", t);
    display_customer(wait);
		t++;
	}
  printf("\n\x1b[32m===== End =====\n\x1b[0m");
	// display_customer(cus);
  printf("평균 대기 시간: %lf\n", average_waiting(cus));
   system("leaks a.out");
  delete_queue(cus);
  delete_queue(wait);
	return (0);
}