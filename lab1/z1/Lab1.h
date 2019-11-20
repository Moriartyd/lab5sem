#pragma once

#include <stdlib.h>
#include <iostream>
#include <string>

typedef struct		s_node
{
	unsigned		id;		//	����� ��� �����
	std::string		date;	//	���� ���������
	unsigned		code;	//	��� ��������
	struct s_node	*next;
}					t_node;

t_node				*push_node(t_node* head);
void				delete_by_code(t_node* head);
t_node*				move_to_new(t_node* head);
void				count_codes(t_node* head);
