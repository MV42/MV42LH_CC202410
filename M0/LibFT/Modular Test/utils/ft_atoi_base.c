/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	base_verif(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i + 1])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j]
				|| base[i] == '-' || base[i] == '+'
				|| base[j] == '-' || base[j] == '+'
				|| base[i] <= 32 || base[i] >= 127
				|| base[j] <= 32 || base[j] >= 127)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	char_is_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sub0;
	int	nbr;
	int	len;

	if (!base_verif(base))
		return (0);
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sub0 = 1;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sub0 *= -1;
	nbr = 0;
	len = ft_strlen(base);
	while (str[i])
	{
		if (char_is_base(str[i], base) < 0)
			return (0);
		nbr *= len;
		nbr += char_is_base(str[i++], base);
	}
	return (nbr * sub0);
}
