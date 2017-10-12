//
//  HazePropertyGroup.h
//  libraries/entities/src
//
//  Created by Nissim hadar on 9/21/17.
//  Copyright 2013 High Fidelity, Inc.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#include <OctreePacketData.h>

#include "HazePropertyGroup.h"
#include "EntityItemProperties.h"
#include "EntityItemPropertiesMacros.h"

const float HazePropertyGroup::DEFAULT_HAZE_RANGE{ 1000.0f };
const xColor HazePropertyGroup::DEFAULT_HAZE_BLEND_IN_COLOR{ 128, 154, 179 };    // Bluish
const xColor HazePropertyGroup::DEFAULT_HAZE_BLEND_OUT_COLOR{ 255, 229, 179 };   // Yellowish
const float HazePropertyGroup::DEFAULT_HAZE_LIGHT_BLEND_ANGLE{ 20.0 };

const float HazePropertyGroup::DEFAULT_HAZE_CEILING{ 200.0f };
const float HazePropertyGroup::DEFAULT_HAZE_BASE_REF{ 0.0f };

const float HazePropertyGroup::DEFAULT_HAZE_BACKGROUND_BLEND{ 0.0f };

const float HazePropertyGroup::DEFAULT_HAZE_KEYLIGHT_RANGE{ 1000.0 };
const float HazePropertyGroup::DEFAULT_HAZE_KEYLIGHT_ALTITUDE{ 200.0f };

void HazePropertyGroup::copyToScriptValue(const EntityPropertyFlags& desiredProperties, QScriptValue& properties, QScriptEngine* engine, bool skipDefaults, EntityItemProperties& defaultEntityProperties) const {
    COPY_GROUP_PROPERTY_TO_QSCRIPTVALUE(PROP_HAZE_RANGE, Haze, haze, HazeRange, hazeRange);
    COPY_GROUP_PROPERTY_TO_QSCRIPTVALUE(PROP_HAZE_BLEND_IN_COLOR, Haze, haze, HazeBlendInColor, hazeBlendInColor);
    COPY_GROUP_PROPERTY_TO_QSCRIPTVALUE(PROP_HAZE_BLEND_OUT_COLOR, Haze, haze, HazeBlendOutColor, hazeBlendOutColor);
    COPY_GROUP_PROPERTY_TO_QSCRIPTVALUE(PROP_HAZE_ENABLE_LIGHT_BLEND, Haze, haze, HazeEnableLightBlend, hazeEnableLightBlend);
    COPY_GROUP_PROPERTY_TO_QSCRIPTVALUE(PROP_HAZE_LIGHT_BLEND_ANGLE, Haze, haze, HazeLightBlendAngle, hazeLightBlendAngle);

    COPY_GROUP_PROPERTY_TO_QSCRIPTVALUE(PROP_HAZE_ALTITUDE, Haze, haze, HazeCeiling, hazeCeiling);
    COPY_GROUP_PROPERTY_TO_QSCRIPTVALUE(PROP_HAZE_BASE_REF, Haze, haze, HazeBaseRef, hazeBaseRef);

    COPY_GROUP_PROPERTY_TO_QSCRIPTVALUE(PROP_HAZE_BACKGROUND_BLEND, Haze, haze, HazeBackgroundBlend, hazeBackgroundBlend);

    COPY_GROUP_PROPERTY_TO_QSCRIPTVALUE(PROP_HAZE_ATTENUATE_KEYLIGHT, Haze, haze, HazeAttenuateKeyLight, hazeAttenuateKeyLight);
    COPY_GROUP_PROPERTY_TO_QSCRIPTVALUE(PROP_HAZE_KEYLIGHT_RANGE, Haze, haze, HazeKeyLightRange, hazeKeyLightRange);
    COPY_GROUP_PROPERTY_TO_QSCRIPTVALUE(PROP_HAZE_KEYLIGHT_ALTITUDE, Haze, haze, HazeKeyLightAltitude, hazeKeyLightAltitude);
}

void HazePropertyGroup::copyFromScriptValue(const QScriptValue& object, bool& _defaultSettings) {
    COPY_GROUP_PROPERTY_FROM_QSCRIPTVALUE(haze, hazeRange, float, setHazeRange);
    COPY_GROUP_PROPERTY_FROM_QSCRIPTVALUE(haze, hazeBlendInColor, xColor, setHazeBlendInColor);
    COPY_GROUP_PROPERTY_FROM_QSCRIPTVALUE(haze, hazeBlendOutColor, xColor, setHazeBlendOutColor);
    COPY_GROUP_PROPERTY_FROM_QSCRIPTVALUE(haze, hazeEnableLightBlend, bool, setHazeEnableLightBlend);
    COPY_GROUP_PROPERTY_FROM_QSCRIPTVALUE(haze, hazeLightBlendAngle, float, setHazeLightBlendAngle);

    COPY_GROUP_PROPERTY_FROM_QSCRIPTVALUE(haze, hazeCeiling, float, setHazeCeiling);
    COPY_GROUP_PROPERTY_FROM_QSCRIPTVALUE(haze, hazeBaseRef, float, setHazeBaseRef);

    COPY_GROUP_PROPERTY_FROM_QSCRIPTVALUE(haze, hazeBackgroundBlend, float, setHazeBackgroundBlend);

    COPY_GROUP_PROPERTY_FROM_QSCRIPTVALUE(haze, hazeAttenuateKeyLight, bool, setHazeAttenuateKeyLight);
    COPY_GROUP_PROPERTY_FROM_QSCRIPTVALUE(haze, hazeKeyLightRange, float, setHazeKeyLightRange);
    COPY_GROUP_PROPERTY_FROM_QSCRIPTVALUE(haze, hazeKeyLightAltitude, float, setHazeKeyLightAltitude);
}

void HazePropertyGroup::merge(const HazePropertyGroup& other) {
    COPY_PROPERTY_IF_CHANGED(hazeRange);
    COPY_PROPERTY_IF_CHANGED(hazeBlendInColor);
    COPY_PROPERTY_IF_CHANGED(hazeBlendOutColor);
    COPY_PROPERTY_IF_CHANGED(hazeEnableLightBlend);
    COPY_PROPERTY_IF_CHANGED(hazeLightBlendAngle);

    COPY_PROPERTY_IF_CHANGED(hazeCeiling);
    COPY_PROPERTY_IF_CHANGED(hazeBaseRef);

    COPY_PROPERTY_IF_CHANGED(hazeBackgroundBlend);

    COPY_PROPERTY_IF_CHANGED(hazeAttenuateKeyLight);
    COPY_PROPERTY_IF_CHANGED(hazeKeyLightRange);
    COPY_PROPERTY_IF_CHANGED(hazeKeyLightAltitude);
}

void HazePropertyGroup::debugDump() const {
    qCDebug(entities) << "   HazePropertyGroup: ---------------------------------------------";

    qCDebug(entities) << "            _hazeRange:" << _hazeRange;
    qCDebug(entities) << "            _hazeBlendInColor:" << _hazeBlendInColor;
    qCDebug(entities) << "            _hazeBlendOutColor:" << _hazeBlendOutColor;
    qCDebug(entities) << "            _hazeEnableLightBlend:" << _hazeEnableLightBlend;
    qCDebug(entities) << "            _hazeLightBlendAngle:" << _hazeLightBlendAngle;

    qCDebug(entities) << "            _hazeCeiling:" << _hazeCeiling;
    qCDebug(entities) << "            _hazeBaseRef:" << _hazeBaseRef;

    qCDebug(entities) << "            _hazeBackgroundBlend:" << _hazeBackgroundBlend;

    qCDebug(entities) << "            _hazeAttenuateKeyLight:" << _hazeAttenuateKeyLight;
    qCDebug(entities) << "            _hazeKeyLightRange:" << _hazeKeyLightRange;
    qCDebug(entities) << "            _hazeKeyLightAltitude:" << _hazeKeyLightAltitude;
}

void HazePropertyGroup::listChangedProperties(QList<QString>& out) {
    if (hazeRangeChanged()) {
        out << "haze-hazeRange";
    }
    if (hazeBlendInColorChanged()) {
        out << "haze-hazeBlendInColor";
    }
    if (hazeBlendOutColorChanged()) {
        out << "haze-hazeBlendOutColor";
    }
    if (hazeEnableLightBlendChanged()) {
        out << "haze-hazeEnableLightBlend";
    }
    if (hazeLightBlendAngleChanged()) {
        out << "haze-hazeLightBlendAngle";
    }

    if (hazeCeilingChanged()) {
        out << "haze-hazeCeiling";
    }
    if (hazeBaseRefChanged()) {
        out << "haze-hazeBaseRef";
    }

    if (hazeBackgroundBlendChanged()) {
        out << "haze-hazeBackgroundBlend";
    }

    if (hazeAttenuateKeyLightChanged()) {
        out << "haze-hazeAttenuateKeyLight";
    }
    if (hazeKeyLightRangeChanged()) {
        out << "haze-hazeKeyLightRange";
    }
    if (hazeKeyLightAltitudeChanged()) {
        out << "haze-hazeKeyLightAltitude";
    }
}

bool HazePropertyGroup::appendToEditPacket(OctreePacketData* packetData,
                                    EntityPropertyFlags& requestedProperties,
                                    EntityPropertyFlags& propertyFlags,
                                    EntityPropertyFlags& propertiesDidntFit,
                                    int& propertyCount, 
                                    OctreeElement::AppendState& appendState) const {

    bool successPropertyFits = true;

    APPEND_ENTITY_PROPERTY(PROP_HAZE_RANGE, getHazeRange());
    APPEND_ENTITY_PROPERTY(PROP_HAZE_BLEND_IN_COLOR, getHazeBlendInColor());
    APPEND_ENTITY_PROPERTY(PROP_HAZE_BLEND_OUT_COLOR, getHazeBlendOutColor());
    APPEND_ENTITY_PROPERTY(PROP_HAZE_ENABLE_LIGHT_BLEND, getHazeEnableLightBlend());
    APPEND_ENTITY_PROPERTY(PROP_HAZE_LIGHT_BLEND_ANGLE, getHazeLightBlendAngle());

    APPEND_ENTITY_PROPERTY(PROP_HAZE_ALTITUDE, getHazeCeiling());
    APPEND_ENTITY_PROPERTY(PROP_HAZE_BASE_REF, getHazeBaseRef());

    APPEND_ENTITY_PROPERTY(PROP_HAZE_BACKGROUND_BLEND, getHazeBackgroundBlend());

    APPEND_ENTITY_PROPERTY(PROP_HAZE_ATTENUATE_KEYLIGHT, getHazeAttenuateKeyLight());
    APPEND_ENTITY_PROPERTY(PROP_HAZE_KEYLIGHT_RANGE, getHazeKeyLightRange());
    APPEND_ENTITY_PROPERTY(PROP_HAZE_KEYLIGHT_ALTITUDE, getHazeKeyLightAltitude());

    return true;
}

bool HazePropertyGroup::decodeFromEditPacket(EntityPropertyFlags& propertyFlags, const unsigned char*& dataAt , int& processedBytes) {

    int bytesRead = 0;
    bool overwriteLocalData = true;
    bool somethingChanged = false;

    READ_ENTITY_PROPERTY(PROP_HAZE_RANGE, float, setHazeRange);
    READ_ENTITY_PROPERTY(PROP_HAZE_BLEND_IN_COLOR, xColor, setHazeBlendInColor);
    READ_ENTITY_PROPERTY(PROP_HAZE_BLEND_OUT_COLOR, xColor, setHazeBlendOutColor);
    READ_ENTITY_PROPERTY(PROP_HAZE_ENABLE_LIGHT_BLEND, bool, setHazeEnableLightBlend);
    READ_ENTITY_PROPERTY(PROP_HAZE_LIGHT_BLEND_ANGLE, float, setHazeLightBlendAngle);

    READ_ENTITY_PROPERTY(PROP_HAZE_ALTITUDE, float, setHazeCeiling);
    READ_ENTITY_PROPERTY(PROP_HAZE_BASE_REF, float, setHazeBaseRef);

    READ_ENTITY_PROPERTY(PROP_HAZE_BACKGROUND_BLEND, float, setHazeBackgroundBlend);

    READ_ENTITY_PROPERTY(PROP_HAZE_ATTENUATE_KEYLIGHT, bool, setHazeAttenuateKeyLight);
    READ_ENTITY_PROPERTY(PROP_HAZE_KEYLIGHT_RANGE, float, setHazeKeyLightRange);
    READ_ENTITY_PROPERTY(PROP_HAZE_KEYLIGHT_ALTITUDE, float, setHazeKeyLightAltitude);

    DECODE_GROUP_PROPERTY_HAS_CHANGED(PROP_HAZE_RANGE, HazeRange);
    DECODE_GROUP_PROPERTY_HAS_CHANGED(PROP_HAZE_BLEND_IN_COLOR, HazeBlendInColor);
    DECODE_GROUP_PROPERTY_HAS_CHANGED(PROP_HAZE_BLEND_OUT_COLOR, HazeBlendOutColor);
    DECODE_GROUP_PROPERTY_HAS_CHANGED(PROP_HAZE_ENABLE_LIGHT_BLEND, HazeEnableLightBlend);
    DECODE_GROUP_PROPERTY_HAS_CHANGED(PROP_HAZE_LIGHT_BLEND_ANGLE, HazeLightBlendAngle);

    DECODE_GROUP_PROPERTY_HAS_CHANGED(PROP_HAZE_ALTITUDE, HazeCeiling);
    DECODE_GROUP_PROPERTY_HAS_CHANGED(PROP_HAZE_BASE_REF, HazeBaseRef);

    DECODE_GROUP_PROPERTY_HAS_CHANGED(PROP_HAZE_BACKGROUND_BLEND, HazeBackgroundBlend);

    DECODE_GROUP_PROPERTY_HAS_CHANGED(PROP_HAZE_ATTENUATE_KEYLIGHT, HazeAttenuateKeyLight);
    DECODE_GROUP_PROPERTY_HAS_CHANGED(PROP_HAZE_KEYLIGHT_RANGE, HazeKeyLightRange);
    DECODE_GROUP_PROPERTY_HAS_CHANGED(PROP_HAZE_KEYLIGHT_ALTITUDE, HazeKeyLightAltitude);

    processedBytes += bytesRead;

    Q_UNUSED(somethingChanged);

    return true;
}

void HazePropertyGroup::markAllChanged() {
    _hazeRangeChanged = true;
    _hazeBlendInColorChanged = true;
    _hazeBlendOutColorChanged = true;
    _hazeEnableLightBlendChanged = true;
    _hazeLightBlendAngleChanged = true;

    _hazeCeilingChanged = true;
    _hazeBaseRefChanged = true;

    _hazeBackgroundBlendChanged = true;

    _hazeAttenuateKeyLightChanged = true;
    _hazeKeyLightRangeChanged = true;
    _hazeKeyLightAltitudeChanged = true;
}

EntityPropertyFlags HazePropertyGroup::getChangedProperties() const {
    EntityPropertyFlags changedProperties;

    CHECK_PROPERTY_CHANGE(PROP_HAZE_RANGE, hazeRange);
    CHECK_PROPERTY_CHANGE(PROP_HAZE_BLEND_IN_COLOR, hazeBlendInColor);
    CHECK_PROPERTY_CHANGE(PROP_HAZE_BLEND_OUT_COLOR, hazeBlendOutColor);
    CHECK_PROPERTY_CHANGE(PROP_HAZE_ENABLE_LIGHT_BLEND, hazeEnableLightBlend);
    CHECK_PROPERTY_CHANGE(PROP_HAZE_LIGHT_BLEND_ANGLE, hazeLightBlendAngle);

    CHECK_PROPERTY_CHANGE(PROP_HAZE_ALTITUDE, hazeCeiling);
    CHECK_PROPERTY_CHANGE(PROP_HAZE_BASE_REF, hazeBaseRef);

    CHECK_PROPERTY_CHANGE(PROP_HAZE_BACKGROUND_BLEND, hazeBackgroundBlend);

    CHECK_PROPERTY_CHANGE(PROP_HAZE_ATTENUATE_KEYLIGHT, hazeAttenuateKeyLight);
    CHECK_PROPERTY_CHANGE(PROP_HAZE_KEYLIGHT_RANGE, hazeKeyLightRange);
    CHECK_PROPERTY_CHANGE(PROP_HAZE_KEYLIGHT_ALTITUDE, hazeKeyLightAltitude);

    return changedProperties;
}

void HazePropertyGroup::getProperties(EntityItemProperties& properties) const {
    COPY_ENTITY_GROUP_PROPERTY_TO_PROPERTIES(Haze, HazeRange, getHazeRange);
    COPY_ENTITY_GROUP_PROPERTY_TO_PROPERTIES(Haze, HazeBlendInColor, getHazeBlendInColor);
    COPY_ENTITY_GROUP_PROPERTY_TO_PROPERTIES(Haze, HazeBlendOutColor, getHazeBlendOutColor);
    COPY_ENTITY_GROUP_PROPERTY_TO_PROPERTIES(Haze, HazeEnableLightBlend, getHazeEnableLightBlend);
    COPY_ENTITY_GROUP_PROPERTY_TO_PROPERTIES(Haze, HazeLightBlendAngle, getHazeLightBlendAngle);

    COPY_ENTITY_GROUP_PROPERTY_TO_PROPERTIES(Haze, HazeCeiling, getHazeCeiling);
    COPY_ENTITY_GROUP_PROPERTY_TO_PROPERTIES(Haze, HazeBaseRef, getHazeBaseRef);

    COPY_ENTITY_GROUP_PROPERTY_TO_PROPERTIES(Haze, HazeBackgroundBlend, getHazeBackgroundBlend);

    COPY_ENTITY_GROUP_PROPERTY_TO_PROPERTIES(Haze, HazeAttenuateKeyLight, getHazeAttenuateKeyLight);
    COPY_ENTITY_GROUP_PROPERTY_TO_PROPERTIES(Haze, HazeKeyLightRange, getHazeKeyLightRange);
    COPY_ENTITY_GROUP_PROPERTY_TO_PROPERTIES(Haze, HazeKeyLightAltitude, getHazeKeyLightAltitude);
}

bool HazePropertyGroup::setProperties(const EntityItemProperties& properties) {
    bool somethingChanged = false;

    SET_ENTITY_GROUP_PROPERTY_FROM_PROPERTIES(Haze, HazeRange, hazeRange, setHazeRange);
    SET_ENTITY_GROUP_PROPERTY_FROM_PROPERTIES(Haze, HazeBlendInColor, hazeBlendInColor, setHazeBlendInColor);
    SET_ENTITY_GROUP_PROPERTY_FROM_PROPERTIES(Haze, HazeBlendOutColor, hazeBlendOutColor, setHazeBlendOutColor);
    SET_ENTITY_GROUP_PROPERTY_FROM_PROPERTIES(Haze, HazeEnableLightBlend, hazeEnableLightBlend, setHazeEnableLightBlend);
    SET_ENTITY_GROUP_PROPERTY_FROM_PROPERTIES(Haze, HazeLightBlendAngle, hazeLightBlendAngle, setHazeLightBlendAngle);

    SET_ENTITY_GROUP_PROPERTY_FROM_PROPERTIES(Haze, HazeCeiling, hazeCeiling, setHazeCeiling);
    SET_ENTITY_GROUP_PROPERTY_FROM_PROPERTIES(Haze, HazeBaseRef, hazeBaseRef, setHazeBaseRef);

    SET_ENTITY_GROUP_PROPERTY_FROM_PROPERTIES(Haze, HazeBackgroundBlend, hazeBackgroundBlend, setHazeBackgroundBlend);

    SET_ENTITY_GROUP_PROPERTY_FROM_PROPERTIES(Haze, HazeAttenuateKeyLight, hazeAttenuateKeyLight, setHazeAttenuateKeyLight);
    SET_ENTITY_GROUP_PROPERTY_FROM_PROPERTIES(Haze, HazeKeyLightRange, hazeKeyLightRange, setHazeKeyLightRange);
    SET_ENTITY_GROUP_PROPERTY_FROM_PROPERTIES(Haze, HazeKeyLightAltitude, hazeKeyLightAltitude, setHazeKeyLightAltitude);

    return somethingChanged;
}

EntityPropertyFlags HazePropertyGroup::getEntityProperties(EncodeBitstreamParams& params) const {
    EntityPropertyFlags requestedProperties;

    requestedProperties += PROP_HAZE_RANGE;
    requestedProperties += PROP_HAZE_BLEND_IN_COLOR;
    requestedProperties += PROP_HAZE_BLEND_OUT_COLOR;
    requestedProperties += PROP_HAZE_ENABLE_LIGHT_BLEND;
    requestedProperties += PROP_HAZE_LIGHT_BLEND_ANGLE;

    requestedProperties += PROP_HAZE_ALTITUDE;
    requestedProperties += PROP_HAZE_BASE_REF;

    requestedProperties += PROP_HAZE_BACKGROUND_BLEND;

    requestedProperties += PROP_HAZE_ATTENUATE_KEYLIGHT;
    requestedProperties += PROP_HAZE_KEYLIGHT_RANGE;
    requestedProperties += PROP_HAZE_KEYLIGHT_ALTITUDE;

    return requestedProperties;
}
    
void HazePropertyGroup::appendSubclassData(OctreePacketData* packetData, EncodeBitstreamParams& params,
                                EntityTreeElementExtraEncodeDataPointer entityTreeElementExtraEncodeData,
                                EntityPropertyFlags& requestedProperties,
                                EntityPropertyFlags& propertyFlags,
                                EntityPropertyFlags& propertiesDidntFit,
                                int& propertyCount, 
                                OctreeElement::AppendState& appendState) const {

    bool successPropertyFits = true;

    APPEND_ENTITY_PROPERTY(PROP_HAZE_RANGE, getHazeRange());
    APPEND_ENTITY_PROPERTY(PROP_HAZE_BLEND_IN_COLOR, getHazeBlendInColor());
    APPEND_ENTITY_PROPERTY(PROP_HAZE_BLEND_OUT_COLOR, getHazeBlendOutColor());
    APPEND_ENTITY_PROPERTY(PROP_HAZE_ENABLE_LIGHT_BLEND, getHazeEnableLightBlend());
    APPEND_ENTITY_PROPERTY(PROP_HAZE_LIGHT_BLEND_ANGLE, getHazeLightBlendAngle());

    APPEND_ENTITY_PROPERTY(PROP_HAZE_ALTITUDE, getHazeCeiling());
    APPEND_ENTITY_PROPERTY(PROP_HAZE_BASE_REF, getHazeBaseRef());

    APPEND_ENTITY_PROPERTY(PROP_HAZE_BACKGROUND_BLEND, getHazeBackgroundBlend());

    APPEND_ENTITY_PROPERTY(PROP_HAZE_ATTENUATE_KEYLIGHT, getHazeAttenuateKeyLight());
    APPEND_ENTITY_PROPERTY(PROP_HAZE_KEYLIGHT_RANGE, getHazeKeyLightRange());
    APPEND_ENTITY_PROPERTY(PROP_HAZE_KEYLIGHT_ALTITUDE, getHazeKeyLightAltitude());
}

int HazePropertyGroup::readEntitySubclassDataFromBuffer(const unsigned char* data, int bytesLeftToRead,
                                            ReadBitstreamToTreeParams& args,
                                            EntityPropertyFlags& propertyFlags, bool overwriteLocalData,
                                            bool& somethingChanged) {

    int bytesRead = 0;
    const unsigned char* dataAt = data;

    READ_ENTITY_PROPERTY(PROP_HAZE_RANGE, float, setHazeRange);
    READ_ENTITY_PROPERTY(PROP_HAZE_BLEND_IN_COLOR, xColor, setHazeBlendInColor);
    READ_ENTITY_PROPERTY(PROP_HAZE_BLEND_OUT_COLOR, xColor, setHazeBlendOutColor);
    READ_ENTITY_PROPERTY(PROP_HAZE_ENABLE_LIGHT_BLEND, bool, setHazeEnableLightBlend);
    READ_ENTITY_PROPERTY(PROP_HAZE_LIGHT_BLEND_ANGLE, float, setHazeLightBlendAngle);

    READ_ENTITY_PROPERTY(PROP_HAZE_ALTITUDE, float, setHazeCeiling);
    READ_ENTITY_PROPERTY(PROP_HAZE_BASE_REF, float, setHazeBaseRef);

    READ_ENTITY_PROPERTY(PROP_HAZE_BACKGROUND_BLEND, float, setHazeBackgroundBlend);

    READ_ENTITY_PROPERTY(PROP_HAZE_ATTENUATE_KEYLIGHT, bool, setHazeAttenuateKeyLight);
    READ_ENTITY_PROPERTY(PROP_HAZE_KEYLIGHT_RANGE, float, setHazeKeyLightRange);
    READ_ENTITY_PROPERTY(PROP_HAZE_KEYLIGHT_ALTITUDE, float, setHazeKeyLightAltitude);

    return bytesRead;
}
