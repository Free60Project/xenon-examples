#ifndef __engine_h
#define __engine_h

#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>
	/* first dumb try of an engine. just to test the GX functions. */

typedef float eMatrix43[3][4];
typedef float eMatrix44[4][4];
typedef float eMatrix33[3][3];
typedef float eMatrixProj[7];
typedef float eViewport[6];
typedef float eVector3[3];

void build_rot_matrix(eMatrix43 dst, float xrot, float yrot, float zrot);
void multiply_matrix(eMatrix43 dst, eMatrix43 s1, eMatrix43 s2);
void multiply_matrix_44(eMatrix44 dst, eMatrix44 s1, eMatrix44 s2);
void build_proj_ortho(eMatrixProj proj, float t, float b, float l, float r, float n, float f);
void build_proj_persp(eMatrixProj proj, float fovy, float aspect, float n, float f);
void invert_matrix(eMatrix43 dst, eMatrix43 src);
void multiply_vector(eVector3 dst, eMatrix43 mtx, eVector3 src);

extern eMatrix43 matrix_stack[128];
extern int matrix_top;

	/* my stupid matrix stack */
void glLoadIdentity();
void glTranslate(float x, float y, float z);
void glRotate(float angle, float x, float y, float z);
void glScale(float x, float y, float z);
void glMultMatrix(eMatrix43 matrix);
void glLoadMatrix(eMatrix43 matrix);

void glPushMatrix();
void glPopMatrix();
void gxLoad();

void gluLookAt(float eyex, float eyey, float eyez, 
		float centerx, float centery, float centerz,
		float upx, float upy, float upz);

#ifdef __cplusplus
};
#endif

#endif
