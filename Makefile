##
## EPITECH PROJECT, 2023
## Makefile_src
## File description:
## Makefile_src
##

SRC		=		src/main.c	\
				src/destroy/destroy_structures.c	\
				src/init/init_values.c	\
				src/init/init_paint.c	\
				src/init/init_colors.c	\
				src/init/init_objects.c	\
				src/init/init_bottombar.c	\
				src/init/init_basic_shapes.c	\
				src/init/init_structures.c	\
				src/init/init_bar_page.c	\
				src/init/init_buttons.c	\
				src/events/mouse_over.c	\
				src/events/event_brushes.c	\
				src/events/event_clipboard.c	\
				src/events/event_colors.c	\
				src/events/event_image.c	\
				src/events/event_shapes.c	\
				src/events/paint_events.c	\
				src/events/file_handling.c	\
				src/events/event_size.c	\
				src/place/place_tools.c	\
				src/place/place_image.c	\
				src/place/place_size.c	\
				src/place/place_shape.c	\
				src/place/place_clipboards.c	\
				src/place/place_colors.c	\
				src/events/event_box.c	\
				src/events/event_box_2.c	\
				src/events/event_creating_box.c	\
				src/features/convert_int_to_str.c	\
				src/features/my_getnbr.c	\
				src/events/check_state.c	\
				src/init/init_pencil.c	\
				src/state/state_tools.c	\
				src/state/state_brush.c	\
				src/state/state_size.c	\
				src/state/state_panel.c	\
				src/chatbox/main_chat/init_chatbox.c	\
				src/chatbox/main_chat/events_chatbox.c	\
				src/chatbox/open_chat/events_open_box.c	\
				src/chatbox/open_chat/init_open_box.c	\
				src/chatbox/main_chat/init_main_scene.c	\
				src/chatbox/main_chat/state_files.c	\

OBJ		=		$(SRC:.c=.o)

MSL		=		-I lib/msl/includes/msl

PSL		=		-I lib/msl/includes/psl

SSL		=		-I lib/msl/includes/ssl

CSL		=		-I lib/msl/includes/csl

MLIB	=		-I lib/msl/includes/


CSFML	=	-lcsfml-system -lcsfml-window -lcsfml-audio -lcsfml-graphics

CFLAGS	=		-I includes/ $(MLIB) $(CSL) $(MSL) $(PSL) $(SSL)

LIB		=		lib/libmsl.a


all:	$(OBJ)
	@$(MAKE) -sC lib/msl/ --no-print-directory
	@gcc -o my_paint $(OBJ) $(LIB) $(CSFML) -Wall -Wextra -g -lm
	@echo "\e[1;32mCompilation done\e[0m"

%.o:	%.c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) fclean -sC lib/msl/ --no-print-directory
	@rm -rf lib/*.a
	@rm -rf $(OBJ)
	@rm -f src/$(OBJ)
	@echo "\e[1;31mclean done\e[0m"

coding-style:
	coding-style.sh . .
	cat coding-style-reports.log
	rm -rf coding-style-reports.log

fclean:	clean
	@rm -rf my_paint
	@echo "\e[1;31mfclean done\e[0m"

re:	fclean	all
