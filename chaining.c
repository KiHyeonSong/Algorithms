#include <stdio.h>

#define TABLE_SIZE 7
#define SIZE 5

typedef struct {
	int key;
} element;

struct list {
	element item;     // 4����Ʈ
	struct list* link;   // 4����Ʈ �ؼ� �� 8����Ʈ
};

struct list* hash_table[TABLE_SIZE];

void hash_chain_search(element item, struct list* ht[]);  // �Լ� ����
void hash_chain_add(element item, struct list* ht[]);     // �Լ� ����
int hash_function(int key);								  // �Լ� ����
void hash_chain_print(struct list* ht[]);                 // �Լ� ����


int main(void)
{
	int data[SIZE] = { 8,1,9,6,13 };   // �迭 ����
	element e;     

	for (int i = 0; i < SIZE; i++)
	{
		e.key = data[i];   //  �����͸� key���� �ִ´�.
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


int hash_function(int key)  // �ؽ� �Լ� �ؽ� �Լ��� ��ġ�� Ű��/SIZE(7)�������� ���´�.
{
	return key % TABLE_SIZE;
}

// ü�̴� �˰��򿡼� ���̺� �߰� �Լ�
void hash_chain_add(element item, struct list* ht[])
{
	int hash_value = hash_function(item.key);   // key���� �ؽ� ������ ����
	struct list* ptr;            // ����Ʈ ������ ���� ����
	// �������� ���� hash_value �� �ε��� ���̺� ����
	struct list* node_before = NULL, *node = ht[hash_value];  // ����Ʈ ������ ���� ����
	// for��  ���� ���� ���� ��带, ���� ���� ���� ��带 ����Ű�鼭 ��� �����Ѵ�
	for (; node; node_before = node, node = node->link)
	{   
		// ����� Ű���� ���� �Է� ���� Ű���� ���� ���
		if (node->item.key == item.key)
		{ // ���
			fprintf(stderr, "�̹� Ž��Ű�� ����Ǿ� ����\n");
			return;
		}
	}
	// �����Ҵ��� �Ѵ�. struct list�� ũ�⸸ŭ
	ptr = (struct list*)malloc(sizeof(struct list));   // 4����Ʈ���ؼ� 8����Ʈ
	ptr->item= item;  // ptr�� �����۰��� �Է¹��� item���� ����
	ptr->link = NULL;  // ptr�� ��ũ�� �� �ڿ� ���� �Ǿ������Ƿ�(����������) ���ᰪ�� NULL�̴�.)
	if (node_before)  // node_before�� NULL�� �ƴϸ�
		node_before->link = ptr;  // node_before�� ����Ű�� ��ũ�� ptr�ּҸ� �����Ѵ�.
	else   // �׷��� ������ node_before�� NULL�̸�
		ht[hash_value] = ptr;  // �ּҸ� �����ϴ� �迭�� ptr�� �ּҸ� �����Ѵ�.
}

// Ž�� �Լ�
void hash_chain_search(element item, struct list* ht[])
{
	struct list* node;
	int hash_value = hash_function(item.key);  // �ؽ��Լ��� ��ȴ� ���� ���ϰ��� hash_value���� ����
	// node�� �ؽ��Լ��� ��ȴ� ���� key���� ����� ������ Ž���Ѵ�. ��� ���� ��ũ�� �Ѿ�鼭 (���Ḯ��Ʈ)
	for (node = ht[hash_value]; node; node = node->link)  
	{   // ��尡 ����Ű�� key���� �Է¹��� key���� ���ٸ� ����Ѵ�.
		if (node ->item.key == item.key)
		{
			fprintf(stderr, "Ž�� %d ���� \n", item.key);
			return;
		}
	}
	// ã�ƺ��µ� ������ ��ã�Ҵٴ� ���
	printf("Ű�� ã�� ������\n");
}

// ������ִ� �Լ�
void hash_chain_print(struct list* ht[])
{
	struct list* node;
	int i;
	printf("\n===============================\n");

	// ���̺� ũ�⸸ŭ ��� ���ư��� ����Ѵ�.
	// Ű��, ���̺� �ε����� ���ư��鼭 ���
	for (i = 0; i < TABLE_SIZE; i++)
	{
		printf("[%d]->", i);
		// ���̺� �ε����� ���� Ű������ ��� ����Ѵ�. 
		// ���Ḯ��Ʈ�� ����Ǿ������� ���� ��ũ�� ��� for���� ���鼭 ����Ѵ�.
		for (node = ht[i]; node; node = node->link)
		{
			// ���
			printf("%d->", node->item.key);
		}
		printf("\n");
	}
	printf("\n===============================\n");
}