#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <cstring>

#define POOL_SIZE 1000
using namespace std;

template<typename T>
class Node {
	public:
		T	data;
		Node<T>	*next;
		Node<T> *prev;
		Node(void) : data(0), next(0), prev(0) {}
		Node(T _data): data(_data), next(0), prev(0) {}
};

template<typename T>
class List {
	private:
		Node<T>	pool[POOL_SIZE];
		Node<T>	*head;
		Node<T>	*tail;
		int		num;
		int		idx;
	public:
		List(void) : num(0), idx(0){
			head = new Node<T>();
			tail = new Node<T>();
			head->next = tail;
			head->prev = 0;
			tail->prev = head;
			tail->next = 0;
			memset(pool, 0, sizeof(pool));
		}
		~List() {
			head = 0;
			tail = 0;
			delete head;
			delete tail;
			memset(pool, 0, sizeof(pool));
			num = 0;
			idx = 0;
		}
		void push_front(T data) {
			pool[idx] = Node<T>(data);
			pool[idx].prev = head;
			pool[idx].next = head->next;
			if (head->next) {
				head->next->prev = &pool[idx];
			}
			head->next = &pool[idx];
			num++;
			idx++;
		}
		void push_back(T data) {
			if (num == 0) {
				push_front(data);
			} else {
				pool[idx] = Node<T>(data);
				tail->prev->next = &pool[idx];
				pool[idx].prev = tail->prev;
				pool[idx].next = tail;
				tail->prev = &pool[idx];
				num++;
				idx++;
			}
		}
		void insert(int in_idx, T data) {
			if (in_idx == 0) {
				push_front(data);
			}
			else if (in_idx == num) {
				push_back(data);
			}
			else {
				Node<T> *now = head->next;
				for (int i = 0; i < in_idx; i++) {
					now = now->next;
				}
				pool[idx] = Node<T>(data);
				pool[idx].next = now;
				pool[idx].prev = now->prev;
				now->prev->next = &pool[idx];
				now->prev = &pool[idx];
				num++;
				idx++;
			}
		}
		void pop_front() {
			if (num == 0)
				return;
			if (num == 1) {
				head->next = tail;
				tail->prev = head;
			} else {
				Node<T> *first = head->next;
				first->next->prev = head;
				head->next = first->next;
			}
			num--;
		}
		void pop_back() {
			if (num < 2) {
				pop_front();
			} else {
				Node<T> *last = tail->prev;
				last->prev->next = tail;
				tail->prev = last->prev;
				num--;
			}

		}
		void erase(int target) {
			if (target == 0) {
				pop_front();
			} else if (target == num - 1) {
				pop_back();
			} else {
				Node<T> *now = head->next;
				for (int i = 0; i < target; i++) {
					now = now->next;
				}
				now->next->prev = now->prev;
				now->prev->next = now->next;
				num--;
			}
		}
		int size() {
			return num;
		}
		void clear() {
			while (num) {
				pop_front();
			}
		}
		void print() {
			Node<T> *now = head->next;
			for (int i = 0; i < num;i++) {
				cout << i << " " << now->data << " \n";
				now = now->next;
			}
		}
};

#endif