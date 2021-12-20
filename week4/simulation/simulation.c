#include "./simulation.h"

void	customer_init(SimCustomer *cust, int arrTime, int svTime)
{
	bzero(cust, sizeof(SimCustomer));
	cust->arrivalTime = arrTime;
	cust->serviceTime = svTime;
}

void	set_arrival(ArrayQueue *cus, ArrayQueue *wait, int time)
{
	t_data	cur;

	cur = peek(cus);
	if (cur.arrivalTime == time)
	{
		dequeue(cus);
		cur.status = arrival;
		enqueue(wait, cur);
	}
}

void	service(ArrayQueue *wait, int time)
{
	t_data	cur;

	if (is_empty(wait) == FALSE)
	{
		cur = peek(wait);
		if (cur.status == arrival)
		{
			wait->pElement[wait->front].element.status = start;
			wait->pElement[wait->front].element.startTime = time;
		}
		else if (cur.status == start)
		{
			if (time - cur.startTime == cur.serviceTime)
			{
				wait->pElement[wait->front].element.status = end;
				wait->pElement[wait->front].element.endTime = cur.startTime + cur.serviceTime;
			}
		}
	}
}

void	service_end(ArrayQueue *cus, ArrayQueue *wait, int time)
{
	t_data	cur;

	cur = peek(wait);
	if (cur.status == end)
	{
		dequeue(wait);
		enqueue(cus, cur);
		if (is_empty(wait) == FALSE)
		{
			wait->pElement[wait->front].element.status = start;
			wait->pElement[wait->front].element.startTime = time;
		}
	}
}

double average_waiting(ArrayQueue *cus)
{
  int waiting = 0;
  for (int i = 0; i < cus->currentElementCount; i++)
    waiting += (cus->pElement[i].element.startTime - cus->pElement[i].element.arrivalTime);
  return ((double)waiting / cus->currentElementCount);
}

void	display_customer(ArrayQueue *cus)
{
	t_data	cur;

	for (int i = 0; i < cus->currentElementCount; i++)
	{
		cur = cus->pElement[(cus->front + i) % cus->maxElementCount].element;
		printf("고객 %d, arrival %d, service %d, start %d, end %d, ", ((cus->front + i) % cus->maxElementCount) + 1, cur.arrivalTime, cur.serviceTime, cur.startTime, cur.endTime);
		switch (cur.status)
		{
			case arrival:
				printf("status %s\n", "arrival");
				break;
			case start:
				printf("status %s\n", "start");
				break;
			case end:
				printf("status %s\n", "end");
				break;
      default:
        printf("status none\n");
        break;
		}
	}
}
