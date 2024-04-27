// Copyright 2024 Stone-Engine

#pragma once

#include "Scene/Node/Node.hpp"
#include "Scene/Transform.hpp"

namespace Stone::Scene {

class PivotNode;

class SkeletonNode : public Node {
public:
	STONE_NODE(SkeletonNode);

	struct Bone {
		std::weak_ptr<PivotNode> pivot;
		glm::mat4 inverseBindMatrix;
		Transform3D restPose;

		explicit Bone(std::shared_ptr<PivotNode> pivot);
	};

	explicit SkeletonNode(const std::string &name = "skeleton");
	SkeletonNode(const SkeletonNode &other);

	virtual ~SkeletonNode();

	std::ostream &writeToStream(std::ostream &stream, bool closing_bracer) const override;

	[[nodiscard]] const std::vector<Bone> &getBones() const;
	void addBone(std::shared_ptr<PivotNode> pivot);
	void addBone(std::shared_ptr<PivotNode> pivot, glm::mat4 offset);

protected:
	std::vector<Bone> _bones;

	[[nodiscard]] const char *_termClassColor() const override;
};

} // namespace Stone::Scene
