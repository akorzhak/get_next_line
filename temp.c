#include "get_next_line.h"

int 	ft_checklist(t_list *list, int fd)
{
	while (list)
	{
		if (list->content_size == fd)
		{
			while (list->content != '\n' && list->content)
			{
				list->content++;
				if (list->content == '\n')
					return (1) 
			}
			return (0);
		}
		list = list->next;
	}
	return (-1);	
}

int 	get_next_line(const int fd, char **line)
{
	static t_list	*list;
	char			buff[BUFF_SIZE + 1];
	int				i;
	int				c;
	int				flag;
	char			temp[];

	list = NULL;
	flag = '-';
	i = 0;
	(list) ? (c = ft_checklist(list, fd)) : 0;
	if (c == -1 || c == 0)
	{
		while (read(fd, buff, BUFF_SIZE) && flag == '-')
		{
			buff[BUFF_SIZE] = '\0';
			while (buff[i])
			{
				if (buff[i] == '\n')
				{
					if (c == -1)
					{
						line = ft_strnew(ft_strlen(i + 1));
						ft_strncpy(line, buff, i);
						ft_lstadd(&list, ft_lstnew(&buff[++i], ft_strlen(&buff[i]))); // ???
					}
					else if (c == 0)
					{
						temp = ft_strncpy(temp, buff, i);
						line = ft_strjoin(list->content, temp); //the content of list + the cont of buff until '\n'
						buff = ft_strrchr(buff, '\n'); //the content starting from '\n'
						buff++; //after '\n'
						ft_lstadd(&list, ft_lstnew(buff, ft_strlen(buff)));
					}
					flag = '+';
					list->content_size = fd
				}
				else
				{
					
				}	
			}
		}