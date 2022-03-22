CC = clang
CFLAGS = -Wall -Werror -Wextra
CLIENT = $(CC) $(CFLAGS) client.c atoi.c ascii_byte.c -o client
SERVER = $(CC) $(CFLAGS) server.c atoi.c ascii_byte.c -o server
NAME_CL = client
NAME_SV = server
all: $(NAME_CL) $(NAME_SV)
$(NAME_CL):
	$(CLIENT)
$(NAME_SV):
	$(SERVER)
clean:
	rm -rf client server
fclean: clean
re: clean all
.PHONY: all clean fclean re