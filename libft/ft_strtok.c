/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:34:06 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/24 10:04:10 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t ft_strspn(const char *s, const char *accept)
{
    const char *p = s;
    const char *a;
    size_t count = 0;

    while (*p != '\0') {
        a = accept;
        while (*a != '\0') {
            if (*p == *a) {
                break;
            }
            ++a;
        }
        if (*a == '\0') {
            return count;
        }
        ++count;
        ++p;
    }
    return count;
}

static size_t ft_strcspn(const char *s, const char *reject)
{
    const char *p = s;
    const char *r;
    size_t count = 0;

    while (*p != '\0') {
        r = reject;
        while (*r != '\0') {
            if (*p == *r) {
                return count;
            }
            ++r;
        }
        ++count;
        ++p;
    }
    return count;
}
char *ft_strtok(char *str, const char *delim) {
    static char *last;
    if (str == NULL) {
        str = last;
    }
    if (str == NULL) {
        return NULL;
    }

    // Skip leading delimiters
    str += ft_strspn(str, delim);
    if (*str == '\0') {
        return NULL;
    }

    // Find the end of the token
    char *end = str + ft_strcspn(str, delim);
    if (*end == '\0') {
        last = NULL;
    } else {
        *end = '\0';
        last = end + 1;
    }

    return str;
}
