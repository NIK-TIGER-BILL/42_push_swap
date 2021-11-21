#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../includes/libft.h"
# include "../includes/get_next_line.h"
typedef struct s_linked
{
	int					number;
	char				head;
	int					order;
	struct s_linked	*next;
	struct s_linked	*previous;
}	t_stack;

typedef struct s_medians
{
	int					num;
	int					step;
}	t_medians;
int			ft_custom_strcmp(char *s1, char *s2);
int			*casher(char **set, int *save);
int			my_exit(int err_num);
void		stack_init(int *cash, int counter);
void		little_sort(t_stack **stack_A, t_stack **stack_B);
void		pre_sorting(t_stack **stack_A, int *cash, int counter);
t_stack		*stack_constructor(int *cash, int counter);
void		roundlst_delfirst(t_stack **stack);
void		roundlst_addfront(t_stack **lst, t_stack *new);
void		roundlst_addback(t_stack **lst, t_stack *new);
t_stack		*lstnew(int content, char head, int order);
void		sort(t_stack **stack_A, t_stack **stack_B);
int			check_arguments(int argc, char **argv, int **cash);
int			check_numbers(char *set, char ***splitted);
int			check_numbers_wo_split(char **splitted);
int			check_doubles(char **set);
long int	ft_atoi_long(const char *str);
void		print_stack(t_stack *stack);
void		swap_a(t_stack **stack_A);
void		swap_b(t_stack **stack_B);
void		swap_both(t_stack **stack_a, t_stack **stack_b);
void		sort_5(t_stack **stack_A, t_stack **stack_B);
void		sort_4(t_stack **stack_A, t_stack **stack_B);
void		sort_3_a(t_stack **stack);
void		sort_3_b(t_stack **stack);
void		roundlst_addfront(t_stack **lst, t_stack *new);
void		roundlst_addback(t_stack **lst, t_stack *new);
void		roundlst_delfirst(t_stack **stack);
void		push_a(t_stack **stack_B, t_stack **stack_A);
void		push_b(t_stack **stack_A, t_stack **stack_B);
void		shift_A(t_stack **stack);
void		shift_B(t_stack **stack);
void		shift_both(t_stack **stack_A, t_stack **stack_B);
void		reverse_shift_A(t_stack **stack);
void		reverse_shift_B(t_stack **stack);
void		reverse_shift_both(t_stack **stack_A, t_stack **stack_B);
int			len_stack(t_stack *stack);
int			sorted_stack(t_stack *stack);
void		check_swap_a(t_stack **stack_A);
void		check_swap_both(t_stack **stack_A, t_stack **stack_B);
void		check_swap_b(t_stack **stack_B);
void		check_shift_A(t_stack **stack_A);
void		check_shift_B(t_stack **stack_B);
void		check_shift_both(t_stack **stack_A, t_stack **stack_B);
void		check_reverse_shift_B(t_stack **stack_B);
void		check_reverse_shift_A(t_stack **stack_A);
void		check_reverse_shift_both(t_stack **stack_A, t_stack **stack_B);
void		check_push_a(t_stack **stack_B, t_stack **stack_A);
void		check_push_b(t_stack **stack_A, t_stack **stack_B);
void		free_stack(t_stack **stack);
void		free_double_array(char **split, int i);
void		free_full_double_array(char **split);
int			ft_strcmp(char *s1, char *s2);
char		*str_prolongate_fabrik(char *arr, char *add);
int			find_next(t_stack *stack_B, t_medians *chunks);
int			find_next_min(t_stack *stack_B, int min);
void		small_sort(t_stack **stack_A, t_stack **stack_B);
#endif
