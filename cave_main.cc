// game made by anders, GPLv2 provided this comment is kept!

#include <allegro5/allegro.h> 

//=================================================
// CONSTANTS
//=================================================
bool keys[] = {false, false, false, false, false}; // måste modifieras
enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE};

int main(int argc, char **argv)
{
  //==============================================
  // PRIMITIVE VARIABLES
  //==============================================
  bool done = false;
  bool render = false;

  float gameTime = 0;
  int frames = 0;
  int game_FPS = 0; // bör ändras
		

  //==============================================
  // ALLEGRO VARIABLES
  //==============================================
  ALLEGRO_DISPLAY *display = NULL;
  ALLEGRO_EVENT_QUEUE *event_queue = NULL;
  ALLEGRO_TIMER *timer;
  ALLEGRO_FONT *font10;
	
  //==============================================
  // ALLEGRO INIT FUNCTIONS
  //==============================================
  if (!al_init()) {
    return -1;
  }
  display = al_create_display(WIDTH, HEIGHT);

  if(!display) {
    return -2;
  }
  
  //==============================================
  // ADDON INSTALL
  //==============================================

  //==============================================
  // PREGAME INIT
  //==============================================

  //==============================================
  //TIMER INIT AND STARTUP
  //==============================================
  event_queue = al_create_event_queue();
  timer = al_create_timer(1.0 / game_FPS);
  
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_register_event_source(event_queue, al_get_keyboard_event_source());
  
  al_start_timer(timer);
  gameTime = al_current_time();

  while (!done) {
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);

      //==============================================
      //INPUT
      //==============================================
      if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
	  switch (ev.keyboard.keycode) {
	    case ALLEGRO_KEY_ESCAPE:
	      done = true;
	      break;
	    case ALLEGRO_KEY_LEFT:
	      keys[LEFT] = true;
	      break;
	    case ALLEGRO_KEY_RIGHT:
	      keys[RIGHT] = true;
	      break;
	    case ALLEGRO_KEY_UP:
	      keys[UP] = true;
	      break;
	    case ALLEGRO_KEY_DOWN:
	      keys[DOWN] = true;
	      break;
	    case ALLEGRO_KEY_SPACE:
	      keys[SPACE] = true;
	      break;
	    }
	}
      else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
	  switch (ev.keyboard.keycode) {
	    case ALLEGRO_KEY_ESCAPE:
	      done = true;
	      break;
	    case ALLEGRO_KEY_LEFT:
	      keys[LEFT] = false;
	      break;
	    case ALLEGRO_KEY_RIGHT:
	      keys[RIGHT] = false;
	      break;
	    case ALLEGRO_KEY_UP:
	      keys[UP] = false;
	      break;
	    case ALLEGRO_KEY_DOWN:
	      keys[DOWN] = false;
	      break;
	    case ALLEGRO_KEY_SPACE:
	      keys[SPACE] = false;
	      break;
	    }
	}
      //==============================================
      //GAME UPDATE
      //==============================================
      else if (ev.type == ALLEGRO_EVENT_TIMER) {
	  render = true;
	  
	  //UPDATE FPS===========
	  frames++;
	  if (al_current_time() - gameTime >= 1) {
	      gameTime = al_current_time();
	      gameFPS = frames;
	      frames = 0;
	    }
	  //=====================
	}
      //==============================================
      // RENDER
      //==============================================
      
      if (render && al_is_event_queue_empty(event_queue)) {
	  render = false;
	  // BEGIN STATUS RENDER =================
	  al_draw_textf(font10, al_map_rgb(255, 0, 255), 5, 5, 0, "FPS: %i", gameFPS);
	  //BEGIN PROJECT RENDER================


	  //FLIP BUFFERS========================
	  al_flip_display();
	  al_clear_to_color(al_map_rgb(0,0,0));
	}
    }

  //==============================================
  // DESTROY PROJECT OBJECTS
  //==============================================
  al_destroy_font(font10);
  al_destroy_timer(timer);
  al_destroy_event_queue(event_queue);
  al_destroy_display(display);

  return 0;
}
