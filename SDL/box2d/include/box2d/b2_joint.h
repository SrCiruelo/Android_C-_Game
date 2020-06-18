// MIT License

// Copyright (c) 2019 Erin Catto

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef B2_JOINT_H
#define B2_JOINT_H

#include "b2_math.h"

class b2Body;
class b2Joint;
struct b2SolverData;
class b2BlockAllocator;

enum b2JointType
{
	e_unknownJoint,
	e_revoluteJoint,
	e_prismaticJoint,
	e_distanceJoint,
	e_pulleyJoint,
	e_mouseJoint,
	e_gearJoint,
	e_wheelJoint,
    e_weldJoint,
	e_frictionJoint,
	e_ropeJoint,
	e_motorJoint
};

enum b2LimitState
{
	e_inactiveLimit,
	e_atLowerLimit,
	e_atUpperLimit,
	e_equalLimits
};

struct b2Jacobian
{
	b2Vec2 linear;
	float angularA;
	float angularB;
};

/// A joint edge is used to connect bodies and joints together
/// in a joint graph where each body is a node and each joint
/// is an edge. A joint edge belongs to a doubly linked list
/// maintained in each attached body. Each joint has two joint
/// nodes, one for each attached body.
struct b2JointEdge
{
	b2Body* other;			///< provides quick access to the other body attached.
	b2Joint* joint;			///< the joint
	b2JointEdge* prev;		///< the previous joint edge in the body's joint list
	b2JointEdge* next;		///< the next joint edge in the body's joint list
};

/// Joint definitions are used to construct joints.
struct b2JointDef
{
	b2JointDef()
	{
		type = e_unknownJoint;
		userData = nullptr;
		bodyA = nullptr;
		bodyB = nullptr;
		collideConnected = false;
	}

	/// The joint type is set automatically for concrete joint types.
	b2JointType type;

	/// Use this to attach application specific data to your joints.
	void* userData;

	/// The first attached body.
	b2Body* bodyA;

	/// The second attached body.
	b2Body* bodyB;

	/// Set this flag to true if the attached bodies should collide.
	bool collideConnected;
};

/// The base joint class. Joints are used to constraint two bodies together in
/// various fashions. Some joints also feature limits and motors.
class b2Joint
{
public:

	/// Get the type of the concrete joint.
	b2JointType GetType() const;

	/// Get the first body attached to this joint.
	b2Body* GetBodyA();

	/// Get the second body attached to this joint.
	b2Body* GetBodyB();

	/// Get the anchor point on bodyA in world coordinates.
	virtual b2Vec2 GetAnchorA() const = 0;

	/// Get the anchor point on bodyB in world coordinates.
	virtual b2Vec2 GetAnchorB() const = 0;

	/// Get the reaction force on bodyB at the joint anchor in Newtons.
	virtual b2Vec2 GetReactionForce(float inv_dt) const = 0;

	/// Get the reaction torque on bodyB in N*m.
	virtual float GetReactionTorque(float inv_dt) const = 0;

	/// Get the next joint the world joint list.
	b2Joint* GetNext();
	const b2Joint* GetNext() const;

	/// Get the user data pointer.
	void* GetUserData() const;

	/// Set the user data pointer.
	void SetUserData(void* data);

	/// Short-cut function to determine if either body is inactive.
	bool IsActive() const;

	/// Get collide connected.
	/// Note: modifying the collide connect flag won't work correctly because
	/// the flag is only checked when fixture AABBs begin to overlap.
	bool GetCollideConnected() const;

	/// Dump this joint to the log file.
	virtual void Dump() { b2Log("// Dump is not supported for this joint type.\n"); }

	/// Shift the origin for any points stored in world coordinates.
	virtual void ShiftOrigin(const b2Vec2& newOrigin) { B2_NOT_USED(newOrigin);  }

protected:
	friend class b2World;
	friend class b2Body;
	friend class b2Island;
	friend class b2GearJoint;

	static b2Joint* Create(const b2JointDef* def, b2BlockAllocator* allocator);
	static void Destroy(b2Joint* joint, b2BlockAllocator* allocator);

	b2Joint(const b2JointDef* def);
	virtual ~b2Joint() {}

	virtual void InitVelocityConstraints(const b2SolverData& data) = 0;
	virtual void SolveVelocityConstraints(const b2SolverData& data) = 0;

	// This returns true if the position errors are within tolerance.
	virtual bool SolvePositionConstraints(const b2SolverData& data) = 0;

	b2JointType m_type;
	b2Joint* m_prev;
	b2Joint* m_next;
	b2JointEdge m_edgeA;
	b2JointEdge m_edgeB;
	b2Body* m_bodyA;
	b2Body* m_bodyB;

	int32 m_index;

	bool m_islandFlag;
	bool m_collideConnected;

	void* m_userData;
};

inline b2JointType b2Joint::GetType() const
{
	return m_type;
}

inline b2Body* b2Joint::GetBodyA()
{
	return m_bodyA;
}

inline b2Body* b2Joint::GetBodyB()
{
	return m_bodyB;
}

inline b2Joint* b2Joint::GetNext()
{
	return m_next;
}

inline const b2Joint* b2Joint::GetNext() const
{
	return m_next;
}

inline void* b2Joint::GetUserData() const
{
	return m_userData;
}

inline void b2Joint::SetUserData(void* data)
{
	m_userData = data;
}

inline bool b2Joint::GetCollideConnected() const
{
	return m_collideConnected;
}

#endif
