/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:15:58 by thakala           #+#    #+#             */
/*   Updated: 2022/09/29 14:25:21 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long double	scale(long double low, int interval, int pos, long double high)
{
	return ((high - low) / (long double) interval * pos);
}
