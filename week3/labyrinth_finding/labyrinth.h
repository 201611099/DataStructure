#ifndef LABYRINTH_H
# define LABYRINTH_H

# include "./stack_list/stack_list.h"
# include "./linked_list/list.h"

typedef ListNode	StackNode;
typedef LinkedList	Stack;

// 계속 가지고 있어야하는 값

/*
 * 1. 미로 출력해주는 함수(플레이어 위치) - 출구 위치
 * 2. 이동했던 경로(stack에 저장된 데이터 출력(좌표))
 * 3. 현재 좌표에서 이동할 수 있는 방향 검사?
 * 4. 현재 좌표 값과 방향을 스택에 push한 후 현재 위치를 1로 만들고 이동
 * 5. 출구에 도달하면 끝
 * 6. 더이상 이동할 방향이 없는경우 pop해서 돌아가기(pop할 때마다 다시 방향 검사)
 * 7. 
 */


//나아갈 수 있는 방향인지 검사 위(dir 0), 오른쪽(dir 1), 아래(dir 2), 왼쪽(dir 3)
//이번에 나아갈 방향 반환 //시작할 때 (dir -1)
//막혀있다면 -1반환


//갈 수 있을 때까지 감
//막힌 길이면 스택에서 pop하고 pop했을 때의 데이터 가지고 그 좌표에서 다음 dir로 다시 검사
//dir을 계속 증가시켜주되 4이상이 되면 출구는 없는 것으로 판단

#endif