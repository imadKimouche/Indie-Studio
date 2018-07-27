//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// AObjectText
//

#ifndef A_OBJECT_TEXT_HPP
#define A_OBJECT_TEXT_HPP

#include "IObject.hpp"

class ObjectText : public IObject {
public:

	ObjectText() : _type(IObject::TEXT), _text(nullptr), _font(""),_color(Color(255,0,0,0)){}
	ObjectText(Coord2 coord, const wchar_t *s, const std::string &font, Color c = Color(255,0,0,0))
	: _type(ObjType::TEXT), _pos2D(coord), _text(s), _font(font), _color(c) {}
	ObjectText(const ObjectText &obj):
		_type(obj._type), _pos2D(obj._pos2D), _text(obj._text), _font(obj._font), _color(obj._color) {}
	virtual ~ObjectText() = default;

	void setPosition2D(Coord2 pos) override { _pos2D = pos; }
	Coord2 getPosition2D() const override { return _pos2D; }
	ObjType getType() const override { return _type; }

	void setFont(const std::string &str) { _font = str; }
	void setText(const wchar_t *str) { _text = str; }
	void setColor(Color color) {_color = color; }

	const wchar_t *getText() const { return _text; }
	const std::string &getFont() const { return _font; }
	Color getColor() const { return _color; }

	void update() override { return; }

protected:

	/* IObject */
	ObjType _type;
	Coord2 _pos2D;

	/* Text Object */
	const wchar_t *_text;
	std::string _font;
	Color _color;

};

#endif
