/* device.h: definition of a container describing a NUT device
 * 
 *  Copyright (C) 2011 - Frederic Bohe <fredericbohe@eaton.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#ifndef SCAN_DEVICE
#define SCAN_DEVICE

typedef enum nutscan_device_type {
	TYPE_NONE=0,
	TYPE_USB,
	TYPE_SNMP,
	TYPE_XML,
	TYPE_NUT,
	TYPE_IPMI,
	TYPE_AVAHI,
	TYPE_END
} nutscan_device_type_t;

typedef struct nutscan_options {
	char *		option;
	char *		value;
	struct nutscan_options*	next;
} nutscan_options_t;

typedef struct nutscan_device {
	nutscan_device_type_t	type;
	char *		driver;
	char *		port;
	nutscan_options_t	opt;
	struct nutscan_device * prev;
	struct nutscan_device * next;
} nutscan_device_t;

nutscan_device_t * nutscan_new_device();
void nutscan_free_device(nutscan_device_t * device);
void nutscan_add_option_to_device(nutscan_device_t * device,char * option, char * value);
nutscan_device_t * nutscan_add_device_to_device(nutscan_device_t * first, nutscan_device_t * second);
#endif