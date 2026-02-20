/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:07:35 by amary             #+#    #+#             */
/*   Updated: 2026/02/18 18:09:31 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int  g_target;
static int *g_vals;
static int  g_count;
static int *g_subset;

static void print_subset(int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        if (i > 0)
            printf(" ");
        printf("%d", g_subset[i]);
    }
    printf("\n");
}

static void dfs(int idx, int sum, int len)
{
    if (idx == g_count)
    {
        if (sum == g_target)
            print_subset(len); /* len can be 0 => prints empty line (empty set) */
        return;
    }

    /* Choice 1: do not take g_vals[idx] */
    dfs(idx + 1, sum, len);

    /* Choice 2: take g_vals[idx] */
    g_subset[len] = g_vals[idx];
    dfs(idx + 1, sum + g_vals[idx], len + 1);
}

int main(int argc, char **argv)
{
    int i;

    if (argc < 2)
        return (0);

    g_target = atoi(argv[1]);
    g_count = argc - 2;

    g_vals = NULL;
    g_subset = NULL;

    if (g_count > 0)
    {
        g_vals = (int *)malloc(sizeof(int) * g_count);
        g_subset = (int *)malloc(sizeof(int) * g_count);
        if (!g_vals || !g_subset)
        {
            free(g_vals);
            free(g_subset);
            return (1);
        }
        for (i = 0; i < g_count; i++)
            g_vals[i] = atoi(argv[i + 2]);
    }
    else
    {
        /* No numbers: only the empty set exists */
        if (g_target == 0)
            printf("\n");
        return (0);
    }

    dfs(0, 0, 0);

    free(g_vals);
    free(g_subset);
    return (0);
}

