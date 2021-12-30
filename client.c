/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:30:05 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/30 17:29:23 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


#include <unistd.h>

void	ftputchar(char c)
{
	write(1, &c, 1);
}

void	ftputnbr( long int nb, long int taille, char *base)
{
	if (nb < 0)
	{
		ftputchar('-');
		nb = -nb;
	}
	if (nb > taille - 1)
	{
		ftputnbr(nb / taille, taille, base);
		ftputnbr(nb %= taille, taille, base);
	}
	else
	{
		ftputchar(base[nb]);
	}
}

int	ftstrlen(char	*str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

void	ftputnbr_base(int	nbr, char	*base)
{
	int	taille_base;
	int	i;
	int	j;

	i = 0;
	taille_base = ftstrlen(base);
	while (base[i])
	{
		if ((base[i] == '-' || base[i] == '+')
			|| ((base[i] >= 9 && base[i] <= 13) || (base[i] == 32)))
			return ;
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return ;
			j++;
		}
		i++;
	}
	if (base[0] == '\0' || ftstrlen(base) == 1)
		return ;
	ftputnbr(nbr, taille_base, base);
}

static void	send_char(char c) 
{ 
	int	bit;
	int f;
	bit = 7; 
	while (bit != -1) 
	{ 
		f = c & (1 << bit);
		if (f) 
		{ 
			printf("%d ", f);
		} 
		else 
		{ 
			printf("%d ", f);
		} 
		bit--; 
		usleep(500); 
	} 
}

void            client(int pid, char *str)
{
    // envoie le signal SIGUSR1 au pid (donc au serveur), return 0 si ok, sinon -1
    if (kill(pid, SIGUSR1))
        ft_putstr_fd(str, 1);
    else
        printf("rate");
}

void    send_char_with_bits(char c)
{
	int i;
	int y = 3;
	int f;
	i = 6;
	//printf("%d\n", f);
	//ftputnbr_base(f, "01");
	while (i >= 0)
	{
		f = 1 << i;
		printf("%d ", f);
		i--;
	}

}

//indique ce que fait SIGUSR1 ou SIGUSR2 (gestionnaire)
// parametre = signal qui l'a activee (1 ou 2 dans notre cas)
static void handler(int signo)
{
    if (signo == SIGUSR1)
        printf("message envoyer bg\n");

}


int main(int ac, char **av)
{
    send_char_with_bits('z');
    //signal(SIGUSR1, &handler);
    //kill(ft_atoi(av[1]), SIGUSR1);
	printf("\n");
    send_char('z');
	printf("\n");
	ftputnbr_base('z', "01");
    //client(ft_atoi(av[1]), av[2]);   
    // kill(ft_atoi(av[1]), SIGUSR1);
    return (0);
}




