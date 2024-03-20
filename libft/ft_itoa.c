/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:09:18 by anomourn          #+#    #+#             */
/*   Updated: 2024/03/14 12:09:20 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_put_num(char *res, int len, long n)
{
	while (len > 0)
	{
		res[len - 1] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	return (res);
}

int	ft_num_len(long n)
{
	long	a;
	int		len;

	a = 1;
	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len = 1;
		n *= -1;
	}
	while (a <= n)
	{
		a *= 10;
		len++;
	}
	return (len);
}

/*alloc (avec malloc) et return un char string representant
int "n" passe en argument.*/
char	*ft_itoa(int n)
{
	int		len;
	char	*res;
	long	nb;

	nb = n;
	len = ft_num_len(nb);
	res = malloc(sizeof(char) * (len + 1));
	res[len] = 0;
	if (!res)
	{
		return (NULL);
	}
	if (nb < 0)
	{
		len--;
		res[0] = '-';
		res = ft_put_num(res + 1, len, ft_absolute(nb));
		res--;
	}
	else
		res = ft_put_num(res, len, nb);
	return (res);
}
