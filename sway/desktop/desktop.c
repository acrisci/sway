#include "sway/tree/container.h"
#include "sway/desktop.h"
#include "sway/output.h"

void desktop_damage_whole_surface(struct wlr_surface *surface, double lx,
		double ly) {
	for (int i = 0; i < root_container.children->length; ++i) {
		struct sway_container *cont = root_container.children->items[i];
		if (cont->type == C_OUTPUT) {
			output_damage_whole_surface(cont->sway_output,
				lx - cont->box.x, ly - cont->box.y, surface);
		}
	}
}

void desktop_damage_from_surface(struct wlr_surface *surface, double lx,
		double ly) {
	// TODO
	desktop_damage_whole_surface(surface, lx, ly);
}