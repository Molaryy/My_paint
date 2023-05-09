/*
** EPITECH PROJECT, 2023
** src_void
** File description:
** src_void
*/

#ifndef SRC_VOID
    #define SRC_VOID
    #define my_printf psl_printf
void init_paint(paint_t *pt);
void init_values(paint_t *pt);
void init_colors(color_t *clr);
void init_objects(sfData_t *data, page_t *pg, color_t *clr);
void destroy_structures(paint_t *pt);
void draw_framebuffer_cercle(page_t *pg, paint_t *pt);
void event_clipboard(sfData_t *data, clipboard_t *cp_b);
void event_brushes(sfData_t *data, brushes_t *brush);
void event_color(sfData_t *data, colorPanel_t *cpn);
void event_image(sfData_t *data, image_t *img);
void event_shapes(sfData_t *data, shapes_t *shape);
void event_size(sfData_t *data, brushSize_t *size);
void place_tools(sfData_t *data, toolbar_t *tb);
void init_bar_page(color_t *clr, sfData_t *data, page_t *pg);
void place_image(sfData_t *data);
void place_size(sfData_t *data);
void place_shape(sfData_t *data);
void place_clipboard(sfData_t *data);
void place_color(sfData_t *data, color_t *clr, colorPanel_t *cpn);
sfCircleShape *ssl_new_cirle(sfData_t data);
void init_main_scene(mainScene_t *sc, color_t *clr);
sfText *init_text(sfVector2f pos, sfVector2f size, char *str);
sfRectangleShape *init_rect(sfVector2f pos, sfVector2f size, sfColor color);
void input_text(paint_t *pt);
void init_bottombar(bottombar_t *btm_br);
void draw_pos_mouse(bottombar_t *btml, sfVector2i mouse);
void handle_settings_page_scale(paint_t *pt);
void handle_settings_page_rgb(paint_t *pt);
void check_if_clicked_box(paint_t *pt);
void check_state(paint_t *pt);
void create_file(paint_t *pt);
void paint_events(paint_t *pt);
void draw_framebuffer_line(page_t *pg, paint_t *pt);
void init_page(page_t *pg);
void update_pixels_2(sfVector2i pos_1,
sfVector2i pos_2, page_t *pg, paint_t *pt);
void expand_pixels(page_t *pg, int x, int y);
void state_tools(paint_t *pt, sfData_t *data, sfVector2i mouse, sfEvent);
void change_panel(paint_t *pt);
void create_buttons(button_paint_t *bp, color_t *clr);
void draw_toolbar_buttons(paint_t *pt);
void init_chatbox(paint_t *pt);
void events_chatbox(paint_t *pt);
void init_open_box(paint_t *pt);
void show_color_rectangle(paint_t *pt);
void state_files (paint_t *pt);
void open_events(paint_t *pt);
#endif /* !SRC_VOID */
