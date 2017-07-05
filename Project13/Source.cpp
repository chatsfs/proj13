#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>

#include "Header.h"

int main() {
	triangulo *movil;
	triangulo2 *movil2;
	movil = new triangulo[1];
	movil2 = new triangulo2[1];
	Insertar_Carro(movil);
	InsertarCarro2(movil2);


	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *imgmovil = NULL;
	ALLEGRO_BITMAP *imgmovil2 = NULL;
	ALLEGRO_BITMAP *imgpared = NULL;
	al_init();
	al_init_primitives_addon();
	al_install_keyboard();
	al_init_image_addon();
	display = al_create_display(800, 600);
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);
	imgmovil = al_load_bitmap("C:\\Users\\QuokkaChats\\Desktop\\Project13\\Carro.bmp");
	imgmovil2 = al_load_bitmap("C:\\Users\\QuokkaChats\\Desktop\\Project13\\Carro2.bmp");
	imgpared = al_load_bitmap("C:\\Users\\QuokkaChats\\Desktop\\Project13\\pared.bmp");
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_start_timer(timer);
	bool dibujar = false;
	while (true) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			break;
		if (ev.type == ALLEGRO_EVENT_TIMER)
			dibujar = true;
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {

			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_LEFT: Mover_Izquierda(movil); break;
			case ALLEGRO_KEY_RIGHT: Mover_Derecha(movil); break;
			case ALLEGRO_KEY_UP: Mover_Arriba(movil); break;
			case ALLEGRO_KEY_DOWN: Mover_Abajo(movil); break;
			case ALLEGRO_KEY_A: MoverIzquierda(movil2); break;
			case ALLEGRO_KEY_D: MoverDerecha(movil2); break;
			case ALLEGRO_KEY_W: MoverArriba(movil2); break;
			case ALLEGRO_KEY_S: MoverAbajo(movil2); break;
			}
		}
		if (dibujar) {
			dibujar = false;
			al_clear_to_color(al_map_rgb(0, 0, 0)); //BORRAMOS TODO
			Mostrar_Carro(movil, imgmovil);
			Mostrar_Carro2(movil2, imgmovil2);
			Dibujar_Mapa(imgpared);
			al_stop_timer(timer);			
			al_start_timer(timer);
			al_flip_display();
			
		}
	}
	al_destroy_display(display);
	al_destroy_timer(timer);
}