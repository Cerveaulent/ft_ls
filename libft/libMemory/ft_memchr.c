/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/28 22:14:23 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 17:49:13 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if a byte from "l" contains the character
*/

static bool				check_byte(unsigned long l, unsigned long l3)
{
	unsigned long		l2;

	l2 = l ^ l3;
	if (_ARCH_)
	{
		if (((l2 - 0x0101010101010101) & (~l2 & 0x8080808080808080)))
			return (true);
	}
	else if (!_ARCH_ && ((l2 - 0x01010101) & (~l2 & 0x80808080)))
		return (true);
	return (false);
}

/*
** Function to read one byte at a time,
** called within the loop until the pointer
** is aligned to a long.
*/

static void				*check_byte_bis(unsigned long l,
										const unsigned long *lp)
{
	if (!(l & 0x000000FF))
		return (void *)((const char *)lp - sizeof(unsigned long));
	if (!(l & 0x0000FF00))
		return (void *)((const char *)lp - (sizeof(unsigned long) - 1));
	if (!(l & 0x00FF0000))
		return (void *)((const char *)lp - (sizeof(unsigned long) - 2));
	if (!(l & 0xFF000000))
		return (void *)((const char *)lp - (sizeof(unsigned long) - 3));
	if (_ARCH_)
	{
		if (!(l & 0x000000FF00000000))
			return (void *)((const char *)lp - (sizeof(unsigned long) - 4));
		if (!(l & 0x0000FF0000000000))
			return (void *)((const char *)lp - (sizeof(unsigned long) - 5));
		if (!(l & 0x00FF000000000000))
			return (void *)((const char *)lp - (sizeof(unsigned long) - 6));
		if (!(l & 0xFF00000000000000))
			return (void *)((const char *)lp - (sizeof(unsigned long) - 7));
	}
	return (NULL);
}

/*
** Reads remaining bytes one by one
*/

static void				*read_rest(const unsigned char *cp, int c, size_t n)
{
	unsigned char		*tmp;

	tmp = (unsigned char *)cp;
	while (n--)
		if (*(tmp++) == (unsigned char)c)
			return ((void *)tmp - 1);
	return (NULL);
}

/*
** Shifts the mask 4 bytes to the left
*/

static unsigned long	offset(unsigned long c)
{
	return (c << 24 | c << 16 | c << 8 | c);
}

void					*ft_memchr(const void *p, int c, size_t n)
{
	const unsigned char	*cp;
	unsigned long		l;
	unsigned long		mask;
	unsigned long		magic;

	cp = p;
	c &= 0xFF;
	while (--n && ((intptr_t)cp & (intptr_t)-sizeof(uint32_t)) < (intptr_t)cp)
		if (*(cp++) == (unsigned char)c)
			return (void *)(cp - 1);
	magic = ((~0UL / 255) * (unsigned char)c);
	mask = offset((unsigned long)c);
	_ARCH_ ? mask = mask << 32 | mask : 0;
	while (n > sizeof(unsigned long))
	{
		if ((check_byte(l, magic)))
			return (NULL);
		l = *((const unsigned long *)((void *)cp++)) ^ mask;
		if (check_byte_bis(l, (const unsigned long *)((void *)cp++)) != NULL)
			return (check_byte_bis(l, (const unsigned long *)((void *)cp++)));
		n -= sizeof(unsigned long);
	}
	cp = (unsigned char *)(void *)((const unsigned long *)((void *)cp));
	return ((unsigned char *)read_rest(cp, c, n));
}
