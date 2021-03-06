/*
Bullet Continuous Collision Detection and Physics Library
Copyright (c) 2003-2006 Erwin Coumans  http://continuousphysics.com/Bullet/

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, 
including commercial applications, and to alter it and redistribute it freely, 
subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/
#ifndef CONCAVE_DEMO_H
#define CONCAVE_DEMO_H

#ifdef _WINDOWS
#include "Win32DemoApplication.h"
#define PlatformDemoApplication Win32DemoApplication
#else
#include "GlutDemoApplication.h"
#define PlatformDemoApplication GlutDemoApplication
#endif

#include "LinearMath/btAlignedObjectArray.h"

class btBroadphaseInterface;
class btCollisionShape;
class btOverlappingPairCache;
class btCollisionDispatcher;
class btConstraintSolver;
struct btCollisionAlgorithmCreateFunc;
class btDefaultCollisionConfiguration;
class btTriangleIndexVertexArray;

///InternalEdgeDemo shows usage of static concave triangle meshes
///It also shows per-triangle material (friction/restitution) through CustomMaterialCombinerCallback
class InternalEdgeDemo : public PlatformDemoApplication
{

	//keep the collision shapes, for deletion/cleanup
	btAlignedObjectArray<btCollisionShape*>	m_collisionShapes;

	btTriangleIndexVertexArray* m_indexVertexArrays;

	btBroadphaseInterface*	m_broadphase;

	btCollisionDispatcher*	m_dispatcher;

	btConstraintSolver*	m_solver;

	btDefaultCollisionConfiguration* m_collisionConfiguration;

	bool	m_animatedMesh;

	public:

	InternalEdgeDemo() : m_animatedMesh(true)
	{

	}
	void	initPhysics();

	void	exitPhysics();

	virtual ~InternalEdgeDemo()
	{
		exitPhysics();
	}

	virtual void	clientResetScene();

	virtual void clientMoveAndDisplay();

	virtual void displayCallback();
	
	//to show refit works
	void	setVertexPositions(float waveheight, float offset);
	
	virtual void keyboardCallback(unsigned char key, int x, int y);
	
	static DemoApplication* Create()
	{
		InternalEdgeDemo* demo = new InternalEdgeDemo();
		demo->myinit();
		demo->initPhysics();
		return demo;
	};
};

#endif //CONCAVE_DEMO_H

