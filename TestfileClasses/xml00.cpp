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

	// XML 파일의 실제 디렉토리를 구한다.
	// 각 플랫폼마다 서로 다른 디렉토리가 나온다.
	// fullPathForFileName 함수가 알아서 각 플랫폼별로 실제 디렉토리를 구해온다.
	std::string path = util->fullPathForFilename("data/test_data.xml");

	tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument();
	XMLError error = doc->LoadFile(path.c_str());

	// 만약 error가 발생했다면 
	if (error != 0)
	{
		log("Error Number: %d", error);
		return false;
	}

	//XML 객체 변수 doc에 로드된 데이터로부터 최상위 요소를 구해온다.
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
	//구해온 값이 배열인 경우 처리 과정이다.
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
	//사용이 완료된 XML 객체 변수 doc를 메모리에서 해제한다.
	delete doc;
	return true;
}
