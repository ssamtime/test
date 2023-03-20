#include "Xml00.h"
#include "tinyxml2/tinyxml2.h"


USING_NS_CC;
using namespace tinyxml2;

Scene* Xml00::createScene()
{
	return Xml00::create();
}

bool Xml00::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	FileUtils* util = FileUtils::getInstance();

	// XML ������ ���� ���丮�� ���Ѵ�.
	// �� �÷������� ���� �ٸ� ���丮�� ���´�.
	// fullPathForFileName �Լ��� �˾Ƽ� �� �÷������� ���� ���丮�� ���ؿ´�.
	std::string path = util->fullPathForFilename("data/test_data.xml");

	tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument();
	XMLError error = doc->LoadFile(path.c_str());

	// ���� error�� �߻��ߴٸ� 
	if (error != 0)
	{
		log("Error Number: %d", error);
		return false;
	}

	//XML ��ü ���� doc�� �ε�� �����ͷκ��� �ֻ��� ��Ҹ� ���ؿ´�.
	XMLElement* root = doc->RootElement();

	XMLElement* val = root->FirstChildElement("total");
	if (val)
	{
		log("val element=%s", val->GetText());
	}

	val = val->NextSiblingElement("page");
	if (val)
	{
		log("val element = %s", val->GetText());
	}

	val = val->NextSiblingElement("per");
	if (val)
	{
		log("val element = %s", val->GetText());
	}
	//���ؿ� ���� �迭�� ��� ó�� �����̴�.
	XMLElement* array = val->NextSiblingElement();
	XMLElement* child = array->FirstChildElement();

	while (child)
	{
		XMLElement* child2 = child->FirstChildElement();
		while (child2)
		{
			log("child element = %s", child2->GetText());
			child2 = child2->NextSiblingElement();
		}
		child = child->NextSiblingElement();
	}
	//����� �Ϸ�� XML ��ü ���� doc�� �޸𸮿��� �����Ѵ�.
	delete doc;
	return true;
}
