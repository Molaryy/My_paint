/*
** EPITECH PROJECT, 2023
** src_int
** File description:
** src_int
*/

#ifndef SRC_INT
    #define SRC_INT
    #include "csl_struct.h"
    #include "src_struct.h"
    int main(int ac, const char **av);
    int init_structures(paint_t *pt);
    int check_a_text(paint_t *pt, int idx_a);
    int check_b_text(paint_t *pt, int idx_b);
    int check_g_text(paint_t *pt, int idx_g);
    bool mouse_over(sfRectangleShape *rect, sfVector2i mouse);
    int my_getnbr(char *str);
    bool find_str_in_str(char *src, char *to_find);
#endif /* !SRC_INT */
