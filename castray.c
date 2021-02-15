// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   castray.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/02/13 19:40:40 by am-khant          #+#    #+#             */
// /*   Updated: 2021/02/15 11:55:12 by am-khant         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "src/cub3d.h"

// void	cast_ray(t_info *info, t_ray *rays,  float rayangl, int strpid)
// {
// 	rayangl = normalize_angle(rayangl);

// 	// t_fcord rays->inter;
// 	// t_fcord rays->step;
// 	t_fcord hwallhit;
	
// 	rays->found_hor = 0;
// 	int horzWallContent = 0;


// 	rays->inter.y = floor(info->player.y / TILE_SIZE) * TILE_SIZE;
// 	rays->inter.y += is_rayfacing_down(rayangl) ? TILE_SIZE : 0;
// 	rays->inter.x = info->player.x + (rays->inter.y - info->player.y) / tan(rayangl);


// 	rays->step.y = TILE_SIZE;
// 	rays->step.y *= is_rayfacing_up(rayangl) ? -1 : 1;

// 	rays->step.x = TILE_SIZE / tan(rayangl);
// 	rays->step.x *= (is_rayfacing_left(rayangl) && rays->step.x > 0) ? -1 : 1;
// 	rays->step.x *= (is_rayfacing_right(rayangl) && rays->step.x < 0) ? -1 : 1;

// 	float nextHorzTouchX = rays->inter.x;
// 	float nextHorzTouchY = rays->inter.y;

// 	while (is_inside_map(nextHorzTouchX, nextHorzTouchY)) {
// 		float xToCheck = nextHorzTouchX;
// 		float yToCheck = nextHorzTouchY + (is_rayfacing_up(rayangl) ? -1 : 0);

// 		if (is_wall(xToCheck, yToCheck)) {
// 			hwallhit.x = nextHorzTouchX;
// 			hwallhit.y = nextHorzTouchY;
// 			rays->found_hor = 1;
// 			break;
// 		} else {
// 			nextHorzTouchX += rays->step.x;
// 			nextHorzTouchY += rays->step.y;
// 		}
// 	}

// 	int foundVertWallHit = 0;
// 	float vertWallHitX = 0;
// 	float vertWallHitY = 0;
// 	int vertWallContent = 0;

// 	rays->inter.x = floor(info->player.x / TILE_SIZE) * TILE_SIZE;
// 	rays->inter.x += is_rayfacing_right(rayangl) ? TILE_SIZE : 0;

// 	rays->inter.y = info->player.y + (rays->inter.x - info->player.x) * tan(rayangl);

// 	rays->step.x = TILE_SIZE;
// 	rays->step.x *= is_rayfacing_left(rayangl) ? -1 : 1;

// 	rays->step.y = TILE_SIZE * tan(rayangl);
// 	rays->step.y *= (is_rayfacing_up(rayangl) && rays->step.y > 0) ? -1 : 1;
// 	rays->step.y *= (is_rayfacing_down(rayangl) && rays->step.y < 0) ? -1 : 1;

// 	float nextVertTouchX = rays->inter.x;
// 	float nextVertTouchY = rays->inter.y;

// 	while (is_inside_map(nextVertTouchX, nextVertTouchY)) {
// 		float xToCheck = nextVertTouchX + (is_rayfacing_left(rayangl) ? -1 : 0);
// 		float yToCheck = nextVertTouchY;

// 		if (is_wall(xToCheck, yToCheck)) {
// 			vertWallHitX = nextVertTouchX;
// 			vertWallHitY = nextVertTouchY;
// 			foundVertWallHit = 1;
// 			break;
// 		} else {
// 			nextVertTouchX += rays->step.x;
// 			nextVertTouchY += rays->step.y;
// 		}
// 	}

// 	float horzHitDistance = rays->found_hor
// 		? dist_btwn_pnts(info->player.x, info->player.y, hwallhit.x, hwallhit.y)
// 		: INT_MAX;
// 	float vertHitDistance = foundVertWallHit
// 		? dist_btwn_pnts(info->player.x, info->player.y, vertWallHitX, vertWallHitY)
// 		: INT_MAX;

// 	if (vertHitDistance < horzHitDistance) {
// 		rays[strpid].distance = vertHitDistance;
// 		rays[strpid].wall.x = vertWallHitX;
// 		rays[strpid].wall.y = vertWallHitY;
// 		rays[strpid].is_vert = 1;
// 		rays[strpid].angle = rayangl;
// 	} else {
// 		rays[strpid].distance = horzHitDistance;
// 		rays[strpid].wall.x = hwallhit.x;
// 		rays[strpid].wall.y = hwallhit.y;
// 		rays[strpid].is_vert = 0;
// 		rays[strpid].angle = rayangl;
// 	}
// }


































// void cast_ray(t_info *info, t_ray *rays,  float rayAngle, int stripId) {
//     rayAngle = normalize_angle(rayAngle);

//     float xintercept, yintercept;
//     float xstep, ystep;

//     ///////////////////////////////////////////
//     // HORIZONTAL RAY-GRID INTERSECTION CODE
//     ///////////////////////////////////////////
//     int foundHorzWallHit = 0;
//     float horzWallHitX = 0;
//     float horzWallHitY = 0;
//     int horzWallContent = 0;

//     // Find the y-coordinate of the closest horizontal grid intersection
//     yintercept = floor(info->player.y / TILE_SIZE) * TILE_SIZE;
//     yintercept += isRayFacingDown(rayAngle) ? TILE_SIZE : 0;

//     // Find the x-coordinate of the closest horizontal grid intersection
//     xintercept = info->player.x + (yintercept - info->player.y) / tan(rayAngle);

//     // Calculate the increment xstep and ystep
//     ystep = TILE_SIZE;
//     ystep *= isRayFacingUp(rayAngle) ? -1 : 1;

//     xstep = TILE_SIZE / tan(rayAngle);
//     xstep *= (isRayFacingLeft(rayAngle) && xstep > 0) ? -1 : 1;
//     xstep *= (isRayFacingRight(rayAngle) && xstep < 0) ? -1 : 1;

//     float nextHorzTouchX = xintercept;
//     float nextHorzTouchY = yintercept;

//     // Increment xstep and ystep until we find a wall
//     while (isInsideMap(nextHorzTouchX, nextHorzTouchY)) {
//         float xToCheck = nextHorzTouchX;
//         float yToCheck = nextHorzTouchY + (isRayFacingUp(rayAngle) ? -1 : 0);

//         if (isWall(xToCheck, yToCheck)) {
//             // found a wall hit
//             horzWallHitX = nextHorzTouchX;
//             horzWallHitY = nextHorzTouchY;
//            // horzWallContent = getMapAt((int)floor(yToCheck / TILE_SIZE), (int)floor(xToCheck / TILE_SIZE));
//             foundHorzWallHit = 1;
//             break;
//         } else {
//             nextHorzTouchX += xstep;
//             nextHorzTouchY += ystep;
//         }
//     }

//     ///////////////////////////////////////////
//     // VERTICAL RAY-GRID INTERSECTION CODE
//     ///////////////////////////////////////////
//     int foundVertWallHit = 0;
//     float vertWallHitX = 0;
//     float vertWallHitY = 0;
//     int vertWallContent = 0;

//     // Find the x-coordinate of the closest horizontal grid intersection
//     xintercept = floor(info->player.x / TILE_SIZE) * TILE_SIZE;
//     xintercept += isRayFacingRight(rayAngle) ? TILE_SIZE : 0;

//     // Find the y-coordinate of the closest horizontal grid intersection
//     yintercept = info->player.y + (xintercept - info->player.x) * tan(rayAngle);

//     // Calculate the increment xstep and ystep
//     xstep = TILE_SIZE;
//     xstep *= isRayFacingLeft(rayAngle) ? -1 : 1;

//     ystep = TILE_SIZE * tan(rayAngle);
//     ystep *= (isRayFacingUp(rayAngle) && ystep > 0) ? -1 : 1;
//     ystep *= (isRayFacingDown(rayAngle) && ystep < 0) ? -1 : 1;

//     float nextVertTouchX = xintercept;
//     float nextVertTouchY = yintercept;

//     // Increment xstep and ystep until we find a wall
//     while (isInsideMap(nextVertTouchX, nextVertTouchY)) {
//         float xToCheck = nextVertTouchX + (isRayFacingLeft(rayAngle) ? -1 : 0);
//         float yToCheck = nextVertTouchY;

//         if (isWall(xToCheck, yToCheck)) {
//             // found a wall hit
//             vertWallHitX = nextVertTouchX;
//             vertWallHitY = nextVertTouchY;
//             //vertWallContent = getMapAt((int)floor(yToCheck / TILE_SIZE), (int)floor(xToCheck / TILE_SIZE));
//             foundVertWallHit = 1;
//             break;
//         } else {
//             nextVertTouchX += xstep;
//             nextVertTouchY += ystep;
//         }
//     }

//     // Calculate both horizontal and vertical hit distances and choose the smallest one
//     float horzHitDistance = foundHorzWallHit
//         ? distanceBetweenPoints(info->player.x, info->player.y, horzWallHitX, horzWallHitY)
//         : INT_MAX;
//     float vertHitDistance = foundVertWallHit
//         ? distanceBetweenPoints(info->player.x, info->player.y, vertWallHitX, vertWallHitY)
//         : INT_MAX;

//     if (vertHitDistance < horzHitDistance) {
//         rays[stripId].distance = vertHitDistance;
//         rays[stripId].wall_x = vertWallHitX;
//         rays[stripId].wall_y = vertWallHitY;
//         //rays[stripId].wallHitContent = vertWallContent;
//         rays[stripId].is_vert = 1;
//         rays[stripId].angle = rayAngle;
//     } else {
//         rays[stripId].distance = horzHitDistance;
//         rays[stripId].wall_x = horzWallHitX;
//         rays[stripId].wall_y = horzWallHitY;
//         //rays[stripId].wallHitContent = horzWallContent;
//         rays[stripId].is_vert = 0;
//         rays[stripId].angle = rayAngle;
//     }
// }
