#ifndef TRUE
# define TRUE 1
# define FALSE 0
#endif

#ifndef YOLO_H
# define YOLO_H
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_meta
{
	char	*name;
	char	*date_last_mod;
	char	*date_cree;
	int	*ssid;
	int	*uid_propri;
	int	*gid_propri;
}		t_meta;

typedef	struct	s_file
{
	s_meta	metadata;
	char	*data;
}		t_file;

typedef	struct	s_dir
{
	s_meta	metadata;
	int	nb_subdir;
	int	nb_file;
	s_dir	*subdir[];
	s_file	*file[];
}		t_dir;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;
	for (i = 0; str[i]; ft_putchar(str[i++]))
		;
}

int	ft_strlen(char *str)
{
	int i;
	for (i = 0; str[i]; i++)
		;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int i;

	for (i = -1; src[++i] && n > 0; n--)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	for (i = 0; dest[i]; i++)
		;
	for (j = 0; src[j]; j++)
		dest[i++] = src[j];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	int i;
	int j;

	for (i = 0; dest[i]; i++)
		;
	for (j = 0; src[j] && n > 0; n--)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

int	ft_strcmp(char *str1, char *str2)
{
	unsigned char c1;
	unsigned char c2;
	int i;

	for (i = 0; str1[i] && str2[i]; i++)
		if (str1[i] != str2[i])
		{
			c1 = str1[i];
			c2 = str2[i];
			return (c1 - c2);
		}
	c1 = str1[i];
	c2 = str2[i];
	return (c1 - c2);
}

int	ft_strncmp(char *str1, char *str2, unsigned int n)
{
	unsigned char c1;
	unsigned char c2;
	int i;

	for (i = 0; str1[i] && str2[i] && n-- > 0; i++)
		if (str1[i] != str2[i])
		{
			c1 = str1[i];
			c2 = str2[i];
			return (c1 - c2);
		}
	c1 = str1[i];
	c2 = str2[i];
	return (c1 - c2);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		i = 0;
		while (str[i] == to_find[i])
			if (to_find[i++] == '\0')
				return (str);
		if (to_find[i] == '\0')
			return (str);
		str++;
	}
	return (NULL);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
}

int	ft_atoi(char *str)
{
	int res;
	int i;

	for (i = 0; (str[i] <= 32 || str[i] == ' ') && str[i]; i++)
		;
	int signe = ((str[i] == '-') ? (-1) : (1));
	if (str[i] == '+')
		i++;
	for (res = 0; str[i] >= '0' && str[i] <= '9'; res = res * 10 + str[i++] - '0')
		;
	return (res * signe);
}

int	ft_pow(int nb, int pow)
{
	return ((pow < 0) ? (0) : ((pow == 0) ? (1) : (nb * ft_pow(nb, pow - 1))));
}

int	ft_sqrt(int nb)
{
	int i;

	i = 0;
	while (i * i <= nb)
		i++;
	return (i - 1);
}

int ft_prime(int nb)
{
	int i;

	i = 1;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	ft_logb(unsigned int base, unsigned int nb)
{
	int res;

	res = 0;
	while (ft_pow(base, res) < nb)
		res++;
	return (res);
}

int	ft_max(int *tab, unsigned int size)
{
	int max = -2147483648;
	do
	{
		if (*tab > max)
			max = *tab;
		tab++;
		size--;
	} while (size);
	return (max);
}

int	**ft_revtabint(int **tab, unsigned int nb_lig, unsigned int nb_col)
{
	int **tab2;
	int i;
	int j;

	for (i = 0; i < nb_col; i++)
		tab2[i] = (int *)malloc(nb_lig * sizeof (int));
	for (i = 0; i < nb_col; i++)
		for (j = 0; j < nb_col; j++)
			tab2[i][j] = tab[j][i];
	for (j = 0; j < nb_col; j++)
		free(tab[j]);
	for (i = 0; i < nb_col; i++)
		tab[i] = (int *)malloc(nb_lig * sizeof (int));
	for (i = 0; i < nb_col; i++)
		for (j = 0; j < nb_col; j++)
			tab[i][j] = tab2[i][j];
	return (tab);
}

void	ft_afftablig(unsigned int nb_col, unsigned int *size)
{
    int i;
    int j;

	for (i = 0; i < nb_col; i++)
	{
		ft_putchar('+');
		for (j = 0; j < size[i]; j++)
			ft_putchar('-');
	}
	ft_putchar('+');
	ft_putchar('\n');
}

void	ft_puttabint(int **tab, unsigned int nb_lig, unsigned int nb_col)
{
	unsigned int *size;
	int i;
	int j;
	int x;

	size = (unsigned int *)malloc(nb_col * sizeof (int));
	tab = ft_revtabint(tab, nb_lig, nb_col);
	for (i = 0; i < nb_col; i++)
		size[i] = ft_logb(10, ft_max(tab[i], nb_lig));
	tab = ft_revtabint(tab, nb_lig, nb_col);
	for (i = 0; i < nb_lig; i++)
	{
		ft_afftablig(nb_col, size);
		for (j = 0; j < nb_col; j++)
		{
			ft_putchar('|');
			ft_putnbr(tab[i][j]);
			for (x = 0; x < size[j] - ft_logb(10, tab[i][j]) + 1; x++)
				ft_putchar(' ');
		}
		ft_putchar('|');
		ft_putchar('\n');
	}
	ft_afftablig(nb_col, size);
}

#endif
