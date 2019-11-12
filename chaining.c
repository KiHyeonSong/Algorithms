#include <stdio.h>

#define TABLE_SIZE 7
#define SIZE 5

typedef struct {
	int key;
} element;

struct list {
	element item;     // 4바이트
	struct list* link;   // 4바이트 해서 총 8바이트
};

struct list* hash_table[TABLE_SIZE];

void hash_chain_search(element item, struct list* ht[]);  // 함수 정의
void hash_chain_add(element item, struct list* ht[]);     // 함수 정의
int hash_function(int key);								  // 함수 정의
void hash_chain_print(struct list* ht[]);                 // 함수 정의


int main(void)
{
	int data[SIZE] = { 8,1,9,6,13 };   // 배열 선언
	element e;     

	for (int i = 0; i < SIZE; i++)
	{
		e.key = data[i];   //  데이터를 key값에 넣는다.
		hash_chain_add(e, hash_table);
		hash_chain_print(hash_table);
	}
	for (int i = 0; i < SIZE; i++)
	{
		e.key = data[i];
		hash_chain_search(e, hash_table);
	}

	return 0;
}


int hash_function(int key)  // 해쉬 함수 해쉬 함수를 거치면 키값/SIZE(7)나머지가 나온다.
{
	return key % TABLE_SIZE;
}

// 체이니 알고리즘에서 테이블 추가 함수
void hash_chain_add(element item, struct list* ht[])
{
	int hash_value = hash_function(item.key);   // key값을 해쉬 값으로 저장
	struct list* ptr;            // 리스트 포인터 변수 선언
	// 나머지로 계산된 hash_value 값 인덱스 테이블에 저장
	struct list* node_before = NULL, *node = ht[hash_value];  // 리스트 포인터 변수 선언
	// for문  이전 노드는 현재 노드를, 현재 노드는 다음 노드를 가리키면서 계속 증가한다
	for (; node; node_before = node, node = node->link)
	{   
		// 노드의 키값이 현재 입력 받은 키값과 같은 경우
		if (node->item.key == item.key)
		{ // 출력
			fprintf(stderr, "이미 탐색키가 저장되어 있음\n");
			return;
		}
	}
	// 동적할당을 한다. struct list의 크기만큼
	ptr = (struct list*)malloc(sizeof(struct list));   // 4바이트씩해서 8바이트
	ptr->item= item;  // ptr의 아이템값은 입력받은 item값을 저장
	ptr->link = NULL;  // ptr의 링크는 맨 뒤에 연결 되어있으므로(마지막으로) 연결값은 NULL이다.)
	if (node_before)  // node_before이 NULL이 아니면
		node_before->link = ptr;  // node_before가 가르키는 링크에 ptr주소를 저장한다.
	else   // 그렇지 않으면 node_before이 NULL이면
		ht[hash_value] = ptr;  // 주소를 저장하는 배열에 ptr의 주소를 저장한다.
}

// 탐색 함수
void hash_chain_search(element item, struct list* ht[])
{
	struct list* node;
	int hash_value = hash_function(item.key);  // 해쉬함수를 들렸다 나온 리턴값을 hash_value값에 저장
	// node는 해쉬함수를 들렸다 나온 key값을 연결된 값들을 탐색한다. 계속 다음 링크로 넘어가면서 (연결리스트)
	for (node = ht[hash_value]; node; node = node->link)  
	{   // 노드가 가르키는 key값이 입력받은 key값과 같다면 출력한다.
		if (node ->item.key == item.key)
		{
			fprintf(stderr, "탐색 %d 성공 \n", item.key);
			return;
		}
	}
	// 찾아보는데 없으면 못찾았다는 출력
	printf("키를 찾지 못했음\n");
}

// 출력해주는 함수
void hash_chain_print(struct list* ht[])
{
	struct list* node;
	int i;
	printf("\n===============================\n");

	// 테이블 크기만큼 계속 돌아가면 출력한다.
	// 키값, 테이블 인덱스를 돌아가면서 출력
	for (i = 0; i < TABLE_SIZE; i++)
	{
		printf("[%d]->", i);
		// 테이블 인덱스에 속한 키값들을 모두 출력한다. 
		// 연결리스트로 연결되어있으면 다음 링크로 계속 for문을 돌면서 출력한다.
		for (node = ht[i]; node; node = node->link)
		{
			// 출력
			printf("%d->", node->item.key);
		}
		printf("\n");
	}
	printf("\n===============================\n");
}