/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:18:14 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/05 11:30:46 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "utils.h"
# include <mlx.h>

# define IMG_SIZE 64

/* piastrelle */
typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	POKEBALL = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	GASTLY = 'M',
	FOLLOWER = 'F',
}	t_tiletype;

typedef struct s_tile
{
	t_tiletype		type;
	t_tiletype		og_type;
	t_vector		position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

/* immagini dei muri */
typedef struct s_wall_img
{
	void	*block;
	void	*up_left;
	void	*up;
	void	*up_right;
	void	*right;
	void	*down_right;
	void	*down;
	void	*down_left;
	void	*left;
}	t_wall_img;

/* pokeball e animazioni */
typedef struct s_pokeball_img
{
	void	*current_img;
	int		anim_frames;
	void	*img_1;
	void	*img_0;
}	t_pokeball_img;

/* effetti vari */
typedef struct s_effect
{
	void		*img;
	t_vector	pos;
	int			frames;
	int			counter;
}	t_effect;

/* immagine che copre la finestra */
typedef struct s_panel
{
	void		*pointer;
	char		*pixels;
	t_vector	size;
	int			bpp;
	int			line_size;
	int			endian;
}	t_panel;

/* colori */
typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		a;
}	t_color;

/* nemici */
typedef enum e_gastlytype
{
	HORIZONTAL_GASTLY = 'H' ,
	VERTICAL_GASTLY = 'V' ,
	FOLLOW_GASTLY = 'F'
}	t_gastlytype;

/* animazioni nemici */
typedef struct s_gastly_img
{
	int		basic_anim;
	void	*basic_current;
	void	*basic_1;
	void	*basic_2;
	int		follow_anim;
	void	*follow_current;
	void	*follow_1;
	void	*follow_2;
}	t_gastly_img;

/* lista nemici */
typedef struct s_gastly
{
	t_gastlytype	type;
	int				dir;
	t_tile			*og_tile;
	t_tile			*tile;
	struct s_gastly	*next;
}	t_gastly;

/* tutti i tasti validi */
enum e_keycode
{
	KEY_W = 13,
	KEY_S = 1,
	KEY_A = 0,
	KEY_D = 2,
	RESET = 15,
	ESC = 53
};

/* info sul protagonista */
typedef struct s_player
{
	t_tile	*tile;
	void	*current_img;
	int		framecount;
	int		idle_frames;
	void	*idle_img_0;
	void	*idle_img_1;
	int		action_frames;
	void	*action_img;
}	t_player;

/* tutte le info sul gioco */
typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_vector		wndw_size;
	t_tile			**tilemap;
	t_player		player;
	int				og_pokeball;
	int				pokeball;
	int				moves;
	t_gastly		*gastly_list;
	t_vector		img_size;
	t_wall_img		wall_imgs;
	t_pokeball_img	pokeball_imgs;
	t_gastly_img	gastly_imgs;
	void			*door_open_img;
	void			*door_close_img;
	t_effect		effect;
	void			*red_panel;
	void			*white_panel;
}	t_game;

/* funzioni */
t_bool	start(t_game *game, int argc, char **argv);
t_color	new_color(int r, int g, int b, int a);
void	*new_panel(t_game *game, t_color color);
int		input(int key, t_game *game);
int		update(t_game *game);
void	render(t_game game);
int		reset(t_game *game);
void	action_anim(t_player *player);
void	effect_anim(t_effect *effect, t_vector pos);
void	remove_player(t_game *game);
void	kill_player(t_game *game, t_vector pos);
int		game_end(t_game *game);
t_bool	move_to(t_game *game, t_tile *tile);
void	move_gastly_to(t_gastly *gastly, t_tile *tile);

#endif
