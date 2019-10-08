#ifndef LAB1_H
# define LAB1_H

#include <stdlib.h>
#include <iostream>
#include <string>

typedef struct		s_node
{
	unsigned		id;		//	Номер мед карты
	std::string			date;	//	Дата обращения
	unsigned		code;	//	Код диагноза
	struct s_node	*next;
}					t_node;

void				push_node(t_node *head, unsigned id);
void				delete_by_code(t_node *head, unsigned code);
t_node				*move_to_new(t_node *head, unsigned id);
unsigned			count_codes(t_node *head, std::string date, unsigned code);

#endif
