template	<typename T>
class		AStack
{
public:
			AStack();
			~AStack();
	bool	empty();
	void	push(T el);
	T		top();
	void	pop();
	T		poll();
private:
	T*		arr;
	int		elements;
};
