module JsValue = {
  type t =
    | String string
    | Float float
    | Int int;
};

module RenderLabel = {
  type t =
    | Boolean Js.boolean
    | Label (float => ReasonReact.reactElement);
};

module Intent = {
  type t =
    | NONE
    | PRIMARY
    | SUCCESS
    | WARNING
    | DANGER;
  let toInt x =>
    switch x {
    | NONE => (-1)
    | PRIMARY => 0
    | SUCCESS => 1
    | WARNING => 2
    | DANGER => 3
    };
  let fromOpt o =>
    switch o {
    | None => Js.Undefined.empty
    | Some x => Js.Undefined.return (toInt x)
    };
};

let unwrapList opt =>
  switch opt {
  | Some b => b |> Array.of_list |> Js.Undefined.return
  | None => Js.Undefined.empty
  };

let unwrapBool opt =>
  switch opt {
  | Some b => b |> Js.Boolean.to_js_boolean |> Js.Undefined.return
  | None => Js.Undefined.empty
  };

module CollapseFrom = {
  type t =
    | START
    | END;
};

module Position = {
  type t =
    | TOP_LEFT
    | TOP
    | TOP_RIGHT
    | RIGHT_TOP
    | RIGHT
    | RIGHT_BOTTOM
    | BOTTOM_RIGHT
    | BOTTOM
    | BOTTOM_LEFT
    | LEFT_BOTTOM
    | LEFT
    | LEFT_TOP;
  external isPositionHorizontal : t => Js.boolean =
    "isPositionHorizontal" [@@bs.module "@blueprintjs/core"];
  let isPositionHorizontal position => Js.to_bool (isPositionHorizontal position);
  external isPositionVertical : t => Js.boolean =
    "isPositionVertical" [@@bs.module "@blueprintjs/core"];
  let isPositionVertical position => Js.to_bool (isPositionVertical position);
};

module Tether = {
  module Constraint = {
    type t =
      Js.t {
        .
        _to : Js.undefined string,
        pin : Js.undefined (Js.Array.t string),
        attachment : Js.undefined string,
        outOfBoundsClass : Js.undefined string,
        pinnedClass : Js.undefined string
      };
  };
  type t =
    Js.t {
      .
      element : Js.undefined string,
      target : Js.undefined string,
      attachment : Js.undefined string,
      targetAttachment : Js.undefined string,
      offset : Js.undefined string,
      targetOffset : Js.undefined string,
      targetModifier : Js.undefined string,
      enabled : Js.undefined Js.boolean,
      classes : Js.undefined (Js.Dict.t string),
      classPrefix : Js.undefined string,
      optimizations : Js.undefined (Js.Dict.t string),
      constraints : Js.Array.t Constraint.t
    };
};

module Alert = {
  type t =
    Js.t {
      .
      cancelButtonText : Js.undefined string,
      className : Js.undefined string,
      confirmButtonText : Js.undefined string,
      iconName : Js.undefined string,
      intent : Js.undefined int,
      isOpen : Js.boolean,
      onCancel : Js.undefined (ReactEventRe.Mouse.t => unit),
      onConfirm : ReactEventRe.Mouse.t => unit,
      style : Js.undefined ReactDOMRe.style
    };
  external reactClass : ReasonReact.reactClass = "Alert" [@@bs.module "@blueprintjs/core"];
  let make
      ::cancelButtonText=?
      ::className=?
      ::confirmButtonText=?
      ::iconName=?
      ::intent=?
      ::isOpen
      ::onCancel=?
      ::onConfirm
      ::style=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "cancelButtonText": cancelButtonText |> Js.Undefined.from_opt,
          "className": className |> Js.Undefined.from_opt,
          "confirmButtonText": confirmButtonText |> Js.Undefined.from_opt,
          "iconName": iconName |> Js.Undefined.from_opt,
          "intent": intent |> Intent.fromOpt,
          "isOpen": Js.Boolean.to_js_boolean isOpen,
          "onCancel": onCancel |> Js.Undefined.from_opt,
          "onConfirm": onConfirm,
          "style": style |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module Breadcrumb = {
  type t =
    Js.t {
      .
      className : Js.undefined string,
      disabled : Js.undefined Js.boolean,
      href : Js.undefined string,
      iconName : Js.undefined string,
      intent : Js.undefined int,
      onClick : Js.undefined (ReactEventRe.Mouse.t => unit),
      target : Js.undefined string,
      text : Js.undefined string
    };
  external reactClass : ReasonReact.reactClass = "Breadcrumb" [@@bs.module "@blueprintjs/core"];
  let make
      ::className=?
      ::disabled=?
      ::href=?
      ::iconName=?
      ::intent=?
      ::onClick=?
      ::target=?
      ::text=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "disabled": disabled |> unwrapBool,
          "href": href |> Js.Undefined.from_opt,
          "iconName": iconName |> Js.Undefined.from_opt,
          "intent": intent |> Intent.fromOpt,
          "onClick": onClick |> Js.Undefined.from_opt,
          "target": target |> Js.Undefined.from_opt,
          "text": text |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module Button = {
  type t =
    Js.t {
      .
      active : Js.undefined Js.boolean,
      className : Js.undefined string,
      disabled : Js.undefined Js.boolean,
      elementRef : Js.undefined (Js.undefined Dom.element => unit),
      iconName : Js.undefined string,
      intent : Js.undefined int,
      loading : Js.undefined Js.boolean,
      onClick : Js.undefined (ReactEventRe.Mouse.t => unit),
      onMouseEnter : Js.undefined (ReactEventRe.Mouse.t => unit),
      onMouseLeave : Js.undefined (ReactEventRe.Mouse.t => unit),
      rightIconName : Js.undefined string,
      text : Js.undefined string,
      _type : Js.undefined string
    };
  external reactClass : ReasonReact.reactClass = "Button" [@@bs.module "@blueprintjs/core"];
  let make
      ::active=?
      ::className=?
      ::disabled=?
      ::elementRef=?
      ::iconName=?
      ::intent=?
      ::loading=?
      ::onClick=?
      ::onMouseEnter=?
      ::onMouseLeave=?
      ::rightIconName=?
      ::text=?
      ::_type=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "active": active |> unwrapBool,
          "className": className |> Js.Undefined.from_opt,
          "disabled": disabled |> unwrapBool,
          "elementRef": elementRef |> Js.Undefined.from_opt,
          "iconName": iconName |> Js.Undefined.from_opt,
          "intent": intent |> Intent.fromOpt,
          "loading": loading |> unwrapBool,
          "onClick": onClick |> Js.Undefined.from_opt,
          "onMouseEnter": onMouseEnter |> Js.Undefined.from_opt,
          "onMouseLeave": onMouseLeave |> Js.Undefined.from_opt,
          "rightIconName": rightIconName |> Js.Undefined.from_opt,
          "text": text |> Js.Undefined.from_opt,
          "_type": Js.Undefined.from_opt _type
        }: t
      )
      children;
};

module AnchorButton = {
  type t =
    Js.t {
      .
      active : Js.undefined Js.boolean,
      className : Js.undefined string,
      disabled : Js.undefined Js.boolean,
      elementRef : Js.undefined (Js.undefined Dom.element => unit),
      iconName : Js.undefined string,
      intent : Js.undefined int,
      loading : Js.undefined Js.boolean,
      onClick : Js.undefined (ReactEventRe.Mouse.t => unit),
      onMouseEnter : Js.undefined (ReactEventRe.Mouse.t => unit),
      onMouseLeave : Js.undefined (ReactEventRe.Mouse.t => unit),
      rightIconName : Js.undefined string,
      text : Js.undefined string
    };
  external reactClass : ReasonReact.reactClass = "AnchorButton" [@@bs.module "@blueprintjs/core"];
  let make
      ::active=?
      ::className=?
      ::disabled=?
      ::elementRef=?
      ::iconName=?
      ::intent=?
      ::loading=?
      ::onClick=?
      ::onMouseEnter=?
      ::onMouseLeave=?
      ::rightIconName=?
      ::text=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "active": active |> unwrapBool,
          "className": className |> Js.Undefined.from_opt,
          "disabled": disabled |> unwrapBool,
          "elementRef": elementRef |> Js.Undefined.from_opt,
          "iconName": iconName |> Js.Undefined.from_opt,
          "intent": intent |> Intent.fromOpt,
          "loading": loading |> unwrapBool,
          "onClick": onClick |> Js.Undefined.from_opt,
          "onMouseEnter": onMouseEnter |> Js.Undefined.from_opt,
          "onMouseLeave": onMouseLeave |> Js.Undefined.from_opt,
          "rightIconName": rightIconName |> Js.Undefined.from_opt,
          "text": text |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module Collapse = {
  type t =
    Js.t {
      .
      className : Js.undefined string,
      component : Js.undefined string,
      isOpen : Js.undefined Js.boolean,
      transitionDuration : Js.undefined int
    };
  external reactClass : ReasonReact.reactClass = "Collapse" [@@bs.module "@blueprintjs/core"];
  let make ::className=? ::component=? ::isOpen=? ::transitionDuration=? children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "component": component |> Js.Undefined.from_opt,
          "isOpen": isOpen |> unwrapBool,
          "transitionDuration": transitionDuration |> Js.Undefined.from_opt
        }: t
      )
      children;
};

/* TODO: ContextMenuTarget */
module Dialog = {
  type t =
    Js.t {
      .
      autoFocus : Js.undefined Js.boolean,
      backdropClassName : Js.undefined string,
      backdropProps : Js.undefined ReactDOMRe.reactDOMProps,
      canEscapeKeyClose : Js.undefined Js.boolean,
      canOutsideClickClose : Js.undefined Js.boolean,
      className : Js.undefined string,
      enforceFocus : Js.undefined Js.boolean,
      hasBackdrop : Js.undefined Js.boolean,
      iconName : Js.undefined string,
      inline : Js.undefined Js.boolean,
      isCloseButtonShown : Js.undefined Js.boolean,
      isOpen : Js.boolean,
      _lazy : Js.undefined Js.boolean,
      onClose : Js.undefined (ReactEventRe.Synthetic.t => unit),
      style : Js.undefined ReactDOMRe.style,
      title : Js.undefined string,
      transitionDuration : Js.undefined int,
      transitionName : Js.undefined string
    };
  external reactClass : ReasonReact.reactClass = "Dialog" [@@bs.module "@blueprintjs/core"];
  let make
      ::autoFocus=?
      ::backdropClassName=?
      ::backdropProps=?
      ::canEscapeKeyClose=?
      ::canOutsideClickClose=?
      ::className=?
      ::enforceFocus=?
      ::hasBackdrop=?
      ::iconName=?
      ::inline=?
      ::isCloseButtonShown=?
      ::isOpen
      ::_lazy=?
      ::onClose=?
      ::style=?
      ::title=?
      ::transitionDuration=?
      ::transitionName=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "autoFocus": autoFocus |> unwrapBool,
          "backdropClassName": backdropClassName |> Js.Undefined.from_opt,
          "backdropProps": backdropProps |> Js.Undefined.from_opt,
          "canEscapeKeyClose": canEscapeKeyClose |> unwrapBool,
          "canOutsideClickClose": canOutsideClickClose |> unwrapBool,
          "className": className |> Js.Undefined.from_opt,
          "enforceFocus": enforceFocus |> unwrapBool,
          "hasBackdrop": hasBackdrop |> unwrapBool,
          "iconName": iconName |> Js.Undefined.from_opt,
          "inline": inline |> unwrapBool,
          "isCloseButtonShown": isCloseButtonShown |> unwrapBool,
          "isOpen": Js.Boolean.to_js_boolean isOpen,
          "_lazy": _lazy |> unwrapBool,
          "onClose": onClose |> Js.Undefined.from_opt,
          "style": style |> Js.Undefined.from_opt,
          "title": title |> Js.Undefined.from_opt,
          "transitionDuration": transitionDuration |> Js.Undefined.from_opt,
          "transitionName": transitionName |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module EditableText = {
  type t =
    Js.t {
      .
      className : Js.undefined string,
      confirmOnEnterKey : Js.undefined Js.boolean,
      defaultValue : Js.undefined string,
      disabled : Js.undefined Js.boolean,
      intent : Js.undefined int,
      isEditing : Js.undefined Js.boolean,
      maxLength : Js.undefined int,
      maxLines : Js.undefined int,
      minLines : Js.undefined int,
      minWidth : Js.undefined int,
      multiline : Js.undefined Js.boolean,
      onCancel : Js.undefined (string => unit),
      onChange : Js.undefined (string => unit),
      onConfirm : Js.undefined (string => unit),
      onEdit : Js.undefined (string => unit),
      placeholder : Js.undefined string,
      selectAllOnFocus : Js.undefined Js.boolean,
      value : Js.undefined string
    };
  external reactClass : ReasonReact.reactClass = "EditableText" [@@bs.module "@blueprintjs/core"];
  let make
      ::className=?
      ::confirmOnEnterKey=?
      ::defaultValue=?
      ::disabled=?
      ::intent=?
      ::isEditing=?
      ::maxLength=?
      ::maxLines=?
      ::minLines=?
      ::minWidth=?
      ::multiline=?
      ::onCancel=?
      ::onChange=?
      ::onConfirm=?
      ::onEdit=?
      ::placeholder=?
      ::selectAllOnFocus=?
      ::value=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "confirmOnEnterKey": confirmOnEnterKey |> unwrapBool,
          "defaultValue": defaultValue |> Js.Undefined.from_opt,
          "disabled": disabled |> unwrapBool,
          "intent": intent |> Intent.fromOpt,
          "isEditing": isEditing |> unwrapBool,
          "maxLength": maxLength |> Js.Undefined.from_opt,
          "maxLines": maxLines |> Js.Undefined.from_opt,
          "minLines": minLines |> Js.Undefined.from_opt,
          "minWidth": minWidth |> Js.Undefined.from_opt,
          "multiline": multiline |> unwrapBool,
          "onCancel": onCancel |> Js.Undefined.from_opt,
          "onChange": onChange |> Js.Undefined.from_opt,
          "onConfirm": onConfirm |> Js.Undefined.from_opt,
          "onEdit": onEdit |> Js.Undefined.from_opt,
          "placeholder": placeholder |> Js.Undefined.from_opt,
          "selectAllOnFocus": selectAllOnFocus |> unwrapBool,
          "value": value |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module Form = {
  type optionProps =
    Js.t {
      .
      className : Js.undefined string,
      disabled : Js.undefined Js.boolean,
      label : string,
      value : string
    };
  module Checkbox = {
    type t =
      Js.t {
        .
        checked : Js.undefined Js.boolean,
        className : Js.undefined string,
        defaultChecked : Js.undefined Js.boolean,
        defaultIndeterminate : Js.undefined Js.boolean,
        disabled : Js.undefined Js.boolean,
        indeterminate : Js.undefined Js.boolean,
        inputRef : Js.undefined (Js.undefined Dom.element => unit),
        label : Js.undefined string,
        labelElement : Js.undefined ReasonReact.reactElement,
        onChange : Js.undefined (ReactEventRe.Form.t => unit)
      };
    external reactClass : ReasonReact.reactClass = "Checkbox" [@@bs.module "@blueprintjs/core"];
    let make
        ::checked=?
        ::className=?
        ::defaultChecked=?
        ::defaultIndeterminate=?
        ::disabled=?
        ::indeterminate=?
        ::inputRef=?
        ::label=?
        ::labelElement=?
        ::onChange=?
        children =>
      ReasonReact.wrapJsForReason
        ::reactClass
        props::(
          {
            "checked": checked |> unwrapBool,
            "className": className |> Js.Undefined.from_opt,
            "defaultChecked": defaultChecked |> unwrapBool,
            "defaultIndeterminate": defaultIndeterminate |> unwrapBool,
            "disabled": disabled |> unwrapBool,
            "indeterminate": indeterminate |> unwrapBool,
            "inputRef": inputRef |> Js.Undefined.from_opt,
            "label": label |> Js.Undefined.from_opt,
            "labelElement": labelElement |> Js.Undefined.from_opt,
            "onChange": onChange |> Js.Undefined.from_opt
          }: t
        )
        children;
  };
  module Switch = {
    type t =
      Js.t {
        .
        checked : Js.undefined Js.boolean,
        className : Js.undefined string,
        defaultChecked : Js.undefined Js.boolean,
        disabled : Js.undefined Js.boolean,
        inputRef : Js.undefined (Js.undefined Dom.element => unit),
        label : Js.undefined string,
        labelElement : Js.undefined ReasonReact.reactElement,
        onChange : Js.undefined (ReactEventRe.Form.t => unit)
      };
    external reactClass : ReasonReact.reactClass = "Switch" [@@bs.module "@blueprintjs/core"];
    let make
        ::checked=?
        ::className=?
        ::defaultChecked=?
        ::disabled=?
        ::inputRef=?
        ::label=?
        ::labelElement=?
        ::onChange=?
        children =>
      ReasonReact.wrapJsForReason
        ::reactClass
        props::(
          {
            "checked": checked |> unwrapBool,
            "className": className |> Js.Undefined.from_opt,
            "defaultChecked": defaultChecked |> unwrapBool,
            "disabled": disabled |> unwrapBool,
            "inputRef": inputRef |> Js.Undefined.from_opt,
            "label": label |> Js.Undefined.from_opt,
            "labelElement": labelElement |> Js.Undefined.from_opt,
            "onChange": onChange |> Js.Undefined.from_opt
          }: t
        )
        children;
  };
  module Radio = {
    type t =
      Js.t {
        .
        checked : Js.undefined Js.boolean,
        className : Js.undefined string,
        defaultChecked : Js.undefined Js.boolean,
        disabled : Js.undefined Js.boolean,
        inputRef : Js.undefined (Js.undefined Dom.element => unit),
        label : Js.undefined string,
        labelElement : Js.undefined ReasonReact.reactElement,
        onChange : Js.undefined (ReactEventRe.Form.t => unit)
      };
    external reactClass : ReasonReact.reactClass = "Radio" [@@bs.module "@blueprintjs/core"];
    let make
        ::checked=?
        ::className=?
        ::defaultChecked=?
        ::disabled=?
        ::inputRef=?
        ::label=?
        ::labelElement=?
        ::onChange=?
        children =>
      ReasonReact.wrapJsForReason
        ::reactClass
        props::(
          {
            "checked": checked |> unwrapBool,
            "className": className |> Js.Undefined.from_opt,
            "defaultChecked": defaultChecked |> unwrapBool,
            "disabled": disabled |> unwrapBool,
            "inputRef": inputRef |> Js.Undefined.from_opt,
            "label": label |> Js.Undefined.from_opt,
            "labelElement": labelElement |> Js.Undefined.from_opt,
            "onChange": onChange |> Js.Undefined.from_opt
          }: t
        )
        children;
  };
  module RadioGroup = {
    type t =
      Js.t {
        .
        className : Js.undefined string,
        disabled : Js.undefined Js.boolean,
        inline : Js.undefined Js.boolean,
        label : Js.undefined string,
        name : Js.undefined string,
        onChange : ReactEventRe.Form.t => unit,
        options : Js.undefined (Js.Array.t optionProps),
        selectedValue : Js.undefined string
      };
    external reactClass : ReasonReact.reactClass = "RadioGroup" [@@bs.module "@blueprintjs/core"];
    let make
        ::className=?
        ::disabled=?
        ::inline=?
        ::label=?
        ::name=?
        ::onChange
        ::options=?
        ::selectedValue=?
        children =>
      ReasonReact.wrapJsForReason
        ::reactClass
        props::(
          {
            "className": className |> Js.Undefined.from_opt,
            "disabled": disabled |> unwrapBool,
            "inline": inline |> unwrapBool,
            "label": label |> Js.Undefined.from_opt,
            "name": name |> Js.Undefined.from_opt,
            "onChange": onChange,
            "options": options |> unwrapList,
            "selectedValue": selectedValue |> Js.Undefined.from_opt
          }: t
        )
        children;
  };
  module InputGroup = {
    type t =
      Js.t {
        .
        className : Js.undefined string,
        defaultValue : Js.undefined string,
        disabled : Js.undefined Js.boolean,
        inputRef : Js.undefined (Js.undefined Dom.element => unit),
        intent : Js.undefined int,
        leftIconName : Js.undefined string,
        onChange : Js.undefined (ReactEventRe.Form.t => unit),
        placeholder : Js.undefined string,
        rightElement : Js.undefined ReasonReact.reactElement,
        _type : Js.undefined string,
        value : Js.undefined string
      };
    external reactClass : ReasonReact.reactClass = "InputGroup" [@@bs.module "@blueprintjs/core"];
    let make
        ::className=?
        ::defaultValue=?
        ::disabled=?
        ::inputRef=?
        ::intent=?
        ::leftIconName=?
        ::onChange=?
        ::placeholder=?
        ::rightElement=?
        ::_type=?
        ::value=?
        children =>
      ReasonReact.wrapJsForReason
        ::reactClass
        props::(
          {
            "className": className |> Js.Undefined.from_opt,
            "defaultValue": defaultValue |> Js.Undefined.from_opt,
            "disabled": disabled |> unwrapBool,
            "inputRef": inputRef |> Js.Undefined.from_opt,
            "intent": intent |> Intent.fromOpt,
            "leftIconName": leftIconName |> Js.Undefined.from_opt,
            "onChange": onChange |> Js.Undefined.from_opt,
            "placeholder": placeholder |> Js.Undefined.from_opt,
            "rightElement": rightElement |> Js.Undefined.from_opt,
            "_type": _type |> Js.Undefined.from_opt,
            "value": value |> Js.Undefined.from_opt
          }: t
        )
        children;
  };
  module NumericInput = {
    type t =
      Js.t {
        .
        allowNumericCharactersOnly : Js.undefined Js.boolean,
        buttonPosition : Js.undefined Position.t,
        clampValueOnBlur : Js.undefined Js.boolean,
        className : Js.undefined string,
        disabled : Js.undefined Js.boolean,
        intent : Js.undefined int,
        large : Js.undefined Js.boolean,
        leftIconName : Js.undefined string,
        majorStepSize : Js.undefined int,
        max : Js.undefined int,
        min : Js.undefined int,
        minorStepSize : Js.undefined int,
        onButtonClick : Js.undefined (int => string => unit),
        onValueClick : Js.undefined (int => string => unit),
        placeholder : Js.undefined string,
        selectAllOnFocus : Js.undefined Js.boolean,
        selectAllOnIncrement : Js.undefined Js.boolean,
        stepSize : Js.undefined int,
        value : Js.undefined JsValue.t
      };
    external reactClass : ReasonReact.reactClass =
      "NumericInput" [@@bs.module "@blueprintjs/core"];
    let make
        ::allowNumericCharactersOnly=?
        ::buttonPosition=?
        ::clampValueOnBlur=?
        ::className=?
        ::disabled=?
        ::intent=?
        ::large=?
        ::leftIconName=?
        ::majorStepSize=?
        ::max=?
        ::min=?
        ::minorStepSize=?
        ::onButtonClick=?
        ::onValueClick=?
        ::placeholder=?
        ::selectAllOnFocus=?
        ::selectAllOnIncrement=?
        ::stepSize=?
        ::value=?
        children =>
      ReasonReact.wrapJsForReason
        ::reactClass
        props::(
          {
            "allowNumericCharactersOnly": allowNumericCharactersOnly |> unwrapBool,
            "buttonPosition": buttonPosition |> Js.Undefined.from_opt,
            "clampValueOnBlur": clampValueOnBlur |> unwrapBool,
            "className": className |> Js.Undefined.from_opt,
            "disabled": disabled |> unwrapBool,
            "intent": intent |> Intent.fromOpt,
            "large": large |> unwrapBool,
            "leftIconName": leftIconName |> Js.Undefined.from_opt,
            "majorStepSize": majorStepSize |> Js.Undefined.from_opt,
            "max": max |> Js.Undefined.from_opt,
            "min": min |> Js.Undefined.from_opt,
            "minorStepSize": minorStepSize |> Js.Undefined.from_opt,
            "onButtonClick": onButtonClick |> Js.Undefined.from_opt,
            "onValueClick": onValueClick |> Js.Undefined.from_opt,
            "placeholder": placeholder |> Js.Undefined.from_opt,
            "selectAllOnFocus": selectAllOnFocus |> unwrapBool,
            "selectAllOnIncrement": selectAllOnIncrement |> unwrapBool,
            "stepSize": stepSize |> Js.Undefined.from_opt,
            "value": value |> Js.Undefined.from_opt
          }: t
        )
        children;
  };
};

/* maybe this works? */
external hotkeysTarget : ReasonReact.reactElement => ReasonReact.reactElement =
  "HotkeysTarget" [@@bs.module "@blueprintjs/core"];

module Hotkeys = {
  type t = Js.t {. className : Js.undefined string, tabIndex : Js.undefined int};
  external reactClass : ReasonReact.reactClass = "Hotkeys" [@@bs.module "@blueprintjs/core"];
  let make ::className=? ::tabIndex=? children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "tabIndex": tabIndex |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module Hotkey = {
  type t =
    Js.t {
      .
      allowInInput : Js.undefined Js.boolean,
      combo : string,
      disabled : Js.undefined Js.boolean,
      global : Js.undefined Js.boolean,
      group : Js.undefined string,
      label : string,
      onKeyDown : Js.undefined (ReactEventRe.Keyboard.t => unit),
      onKeyUp : Js.undefined (ReactEventRe.Keyboard.t => unit),
      preventDefault : Js.undefined Js.boolean,
      stopPropagation : Js.undefined Js.boolean
    };
  external reactClass : ReasonReact.reactClass = "Hotkey" [@@bs.module "@blueprintjs/core"];
  let make
      ::allowInInput=?
      ::combo
      ::disabled=?
      ::global=?
      ::group=?
      ::label
      ::onKeyDown=?
      ::onKeyUp=?
      ::preventDefault=?
      ::stopPropagation=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "allowInInput": allowInInput |> unwrapBool,
          "combo": combo,
          "disabled": disabled |> unwrapBool,
          "global": global |> unwrapBool,
          "group": group |> Js.Undefined.from_opt,
          "label": label,
          "onKeyDown": onKeyDown |> Js.Undefined.from_opt,
          "onKeyUp": onKeyUp |> Js.Undefined.from_opt,
          "preventDefault": preventDefault |> unwrapBool,
          "stopPropagation": stopPropagation |> unwrapBool
        }: t
      )
      children;
};

module Menu = {
  type t =
    Js.t {
      .
      className : Js.undefined string, uiRef : Js.undefined (Js.undefined Dom.element => unit)
    };
  external reactClass : ReasonReact.reactClass = "Menu" [@@bs.module "@blueprintjs/core"];
  let make ::className=? ::uiRef=? children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {"className": className |> Js.Undefined.from_opt, "uiRef": uiRef |> Js.Undefined.from_opt}: t
      )
      children;
};

module MenuItem = {
  module SubmenuViewportMargin = {
    type t = Js.t {. left : Js.undefined int, right : Js.undefined int};
  };
  type t =
    Js.t {
      .
      className : Js.undefined string,
      disabled : Js.undefined Js.boolean,
      href : Js.undefined string,
      iconName : Js.undefined string,
      intent : Js.undefined int,
      label : Js.undefined ReasonReact.reactElement,
      onClick : Js.undefined (ReactEventRe.Mouse.t => unit),
      shouldDismissPopover : Js.undefined Js.boolean,
      submenu : Js.undefined t,
      submenuViewportMargin : Js.undefined SubmenuViewportMargin.t,
      target : Js.undefined string,
      text : string,
      useSmartPositioning : Js.undefined Js.boolean
    };
  external reactClass : ReasonReact.reactClass = "MenuItem" [@@bs.module "@blueprintjs/core"];
  let make
      ::className=?
      ::disabled=?
      ::href=?
      ::iconName=?
      ::intent=?
      ::label=?
      ::onClick=?
      ::shouldDismissPopover=?
      ::submenu=?
      ::submenuViewportMargin=?
      ::target=?
      ::text
      ::useSmartPositioning=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "disabled": disabled |> unwrapBool,
          "href": href |> Js.Undefined.from_opt,
          "iconName": iconName |> Js.Undefined.from_opt,
          "intent": intent |> Intent.fromOpt,
          "onClick": onClick |> Js.Undefined.from_opt,
          "label": label |> Js.Undefined.from_opt,
          "shouldDismissPopover": shouldDismissPopover |> unwrapBool,
          "submenu": submenu |> Js.Undefined.from_opt,
          "submenuViewportMargin": submenuViewportMargin |> Js.Undefined.from_opt,
          "target": target |> Js.Undefined.from_opt,
          "text": text,
          "useSmartPositioning": useSmartPositioning |> unwrapBool
        }: t
      )
      children;
};

module MenuDivider = {
  type t = Js.t {. className : Js.undefined string, title : Js.undefined string};
  external reactClass : ReasonReact.reactClass = "MenuDivider" [@@bs.module "@blueprintjs/core"];
  let make ::className=? ::title=? children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {"className": className |> Js.Undefined.from_opt, "title": title |> Js.Undefined.from_opt}: t
      )
      children;
};

module NonIdealState = {
  type t =
    Js.t {
      .
      action : Js.undefined ReasonReact.reactElement,
      className : Js.undefined string,
      description : Js.undefined ReasonReact.reactElement,
      title : Js.undefined string,
      visual : Js.undefined ReasonReact.reactElement
    };
  external reactClass : ReasonReact.reactClass = "NonIdealState" [@@bs.module "@blueprintjs/core"];
  let make ::action=? ::className=? ::description=? ::title=? ::visual=? children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "action": action |> Js.Undefined.from_opt,
          "className": className |> Js.Undefined.from_opt,
          "description": description |> Js.Undefined.from_opt,
          "title": title |> Js.Undefined.from_opt,
          "visual": visual |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module Overlay = {
  type t =
    Js.t {
      .
      autoFocus : Js.undefined Js.boolean,
      backdropClassName : Js.undefined string,
      backdropProps : Js.undefined ReactDOMRe.reactDOMProps,
      canEscapeKeyClose : Js.undefined Js.boolean,
      canOutsideClickClose : Js.undefined Js.boolean,
      className : Js.undefined string,
      didOpen : Js.undefined (unit => unit),
      enforceFocus : Js.undefined Js.boolean,
      hasBackdrop : Js.undefined Js.boolean,
      inline : Js.undefined Js.boolean,
      isOpen : Js.boolean,
      _lazy : Js.undefined Js.boolean,
      onClose : Js.undefined (ReactEventRe.Synthetic.t => unit),
      transitionDuration : Js.undefined int,
      transitionName : Js.undefined string
    };
  external reactClass : ReasonReact.reactClass = "Overlay" [@@bs.module "@blueprintjs/core"];
  let make
      ::autoFocus=?
      ::backdropClassName=?
      ::backdropProps=?
      ::canEscapeKeyClose=?
      ::canOutsideClickClose=?
      ::className=?
      ::didOpen=?
      ::enforceFocus=?
      ::hasBackdrop=?
      ::inline=?
      ::isOpen
      ::_lazy=?
      ::onClose=?
      ::transitionDuration=?
      ::transitionName=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "autoFocus": autoFocus |> unwrapBool,
          "backdropClassName": backdropClassName |> Js.Undefined.from_opt,
          "backdropProps": backdropProps |> Js.Undefined.from_opt,
          "canEscapeKeyClose": canEscapeKeyClose |> unwrapBool,
          "canOutsideClickClose": canOutsideClickClose |> unwrapBool,
          "className": className |> Js.Undefined.from_opt,
          "didOpen": didOpen |> Js.Undefined.from_opt,
          "enforceFocus": enforceFocus |> unwrapBool,
          "hasBackdrop": hasBackdrop |> unwrapBool,
          "inline": inline |> unwrapBool,
          "isOpen": Js.Boolean.to_js_boolean isOpen,
          "_lazy": _lazy |> unwrapBool,
          "onClose": onClose |> Js.Undefined.from_opt,
          "transitionDuration": transitionDuration |> Js.Undefined.from_opt,
          "transitionName": transitionName |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module Popover = {
  type t =
    Js.t {
      .
      autoFocus : Js.undefined Js.boolean,
      backdropProps : Js.undefined ReactDOMRe.reactDOMProps,
      canEscapeKeyClose : Js.undefined Js.boolean,
      className : Js.undefined string,
      content : Js.undefined ReasonReact.reactElement,
      defaultIsOpen : Js.undefined Js.boolean,
      enforceFocus : Js.undefined Js.boolean,
      hoverCloseDelay : Js.undefined int,
      hoverOpenDelay : Js.undefined int,
      inheritDarkTheme : Js.undefined Js.boolean,
      inline : Js.undefined Js.boolean,
      interactionKind : Js.undefined Js.boolean,
      isDisabled : Js.undefined Js.boolean,
      isModal : Js.undefined Js.boolean,
      isOpen : Js.undefined Js.boolean,
      _lazy : Js.undefined Js.boolean,
      onClose : Js.undefined (ReactEventRe.Synthetic.t => unit),
      onInteraction : Js.undefined (Js.boolean => unit),
      openOnTargetFocus : Js.undefined Js.boolean,
      popoverClassName : Js.undefined string,
      popoverDidOpen : Js.undefined (unit => unit),
      popoverWillClose : Js.undefined (unit => unit),
      popoverWillOpen : Js.undefined (unit => unit),
      portalClassName : Js.undefined string,
      position : Js.undefined Position.t,
      rootElementTag : Js.undefined string,
      target : Js.undefined ReasonReact.reactElement,
      tetherOptions : Js.undefined Tether.t,
      transitionDuration : Js.undefined int,
      useSmartArrowPositioning : Js.undefined Js.boolean
    };
  external reactClass : ReasonReact.reactClass = "Popover" [@@bs.module "@blueprintjs/core"];
  let make
      ::autoFocus=?
      ::backdropProps=?
      ::canEscapeKeyClose=?
      ::className=?
      ::content=?
      ::defaultIsOpen=?
      ::enforceFocus=?
      ::hoverCloseDelay=?
      ::hoverOpenDelay=?
      ::inheritDarkTheme=?
      ::inline=?
      ::interactionKind=?
      ::isDisabled=?
      ::isModal=?
      ::isOpen=?
      ::_lazy=?
      ::onClose=?
      ::onInteraction=?
      ::openOnTargetFocus=?
      ::popoverClassName=?
      ::popoverDidOpen=?
      ::popoverWillClose=?
      ::popoverWillOpen=?
      ::portalClassName=?
      ::position=?
      ::rootElementTag=?
      ::target=?
      ::tetherOptions=?
      ::transitionDuration=?
      ::useSmartArrowPositioning=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "autoFocus": autoFocus |> unwrapBool,
          "backdropProps": backdropProps |> Js.Undefined.from_opt,
          "canEscapeKeyClose": canEscapeKeyClose |> unwrapBool,
          "className": className |> Js.Undefined.from_opt,
          "content": content |> Js.Undefined.from_opt,
          "defaultIsOpen": defaultIsOpen |> unwrapBool,
          "enforceFocus": enforceFocus |> unwrapBool,
          "hoverCloseDelay": hoverCloseDelay |> Js.Undefined.from_opt,
          "hoverOpenDelay": hoverOpenDelay |> Js.Undefined.from_opt,
          "inheritDarkTheme": inheritDarkTheme |> unwrapBool,
          "inline": inline |> unwrapBool,
          "interactionKind": interactionKind |> Js.Undefined.from_opt,
          "isDisabled": isDisabled |> unwrapBool,
          "isModal": isModal |> unwrapBool,
          "isOpen": isOpen |> unwrapBool,
          "_lazy": _lazy |> unwrapBool,
          "onClose": onClose |> Js.Undefined.from_opt,
          "onInteraction": onInteraction |> Js.Undefined.from_opt,
          "openOnTargetFocus": openOnTargetFocus |> unwrapBool,
          "popoverClassName": popoverClassName |> Js.Undefined.from_opt,
          "popoverDidOpen": popoverDidOpen |> Js.Undefined.from_opt,
          "popoverWillClose": popoverWillClose |> Js.Undefined.from_opt,
          "popoverWillOpen": popoverWillOpen |> Js.Undefined.from_opt,
          "portalClassName": portalClassName |> Js.Undefined.from_opt,
          "position": position |> Js.Undefined.from_opt,
          "rootElementTag": rootElementTag |> Js.Undefined.from_opt,
          "target": target |> Js.Undefined.from_opt,
          "tetherOptions": tetherOptions |> Js.Undefined.from_opt,
          "transitionDuration": transitionDuration |> Js.Undefined.from_opt,
          "useSmartArrowPositioning": useSmartArrowPositioning |> unwrapBool
        }: t
      )
      children;
};

module Portal = {
  type t =
    Js.t {
      .
      className : Js.undefined string,
      containerRef : Js.undefined (Js.undefined Dom.element => unit),
      onChildrenMount : Js.undefined (unit => unit)
    };
  external reactClass : ReasonReact.reactClass = "Portal" [@@bs.module "@blueprintjs/core"];
  let make ::className=? ::containerRef=? ::onChildrenMount=? children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "containerRef": containerRef |> Js.Undefined.from_opt,
          "onChildrenMount": onChildrenMount |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module ProgressBar = {
  type t =
    Js.t {
      .
      className : Js.undefined string, intent : Js.undefined int, value : Js.undefined float
    };
  external reactClass : ReasonReact.reactClass = "ProgressBar" [@@bs.module "@blueprintjs/core"];
  let make ::className=? ::intent=? ::value=? children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "intent": intent |> Intent.fromOpt,
          "value": value |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module Spinner = {
  type t =
    Js.t {
      .
      className : Js.undefined string, intent : Js.undefined int, value : Js.undefined float
    };
  external reactClass : ReasonReact.reactClass = "Spinner" [@@bs.module "@blueprintjs/core"];
  let make ::className=? ::intent=? ::value=? children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "intent": intent |> Intent.fromOpt,
          "value": value |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module Slider = {
  type t =
    Js.t {
      .
      className : Js.undefined string,
      disabled : Js.undefined Js.boolean,
      initialValue : Js.undefined float,
      labelStepSize : Js.undefined int,
      max : Js.undefined float,
      min : Js.undefined float,
      onChange : Js.undefined (float => unit),
      onRelease : Js.undefined (float => unit),
      renderLabel : Js.undefined RenderLabel.t,
      showTrackFill : Js.undefined Js.boolean,
      stepSize : Js.undefined int,
      value : Js.undefined float
    };
  external reactClass : ReasonReact.reactClass = "Slider" [@@bs.module "@blueprintjs/core"];
  let make
      ::className=?
      ::disabled=?
      ::initialValue=?
      ::labelStepSize=?
      ::max=?
      ::min=?
      ::onChange=?
      ::onRelease=?
      ::renderLabel=?
      ::showTrackFill=?
      ::stepSize=?
      ::value=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "disabled": disabled |> unwrapBool,
          "initialValue": initialValue |> Js.Undefined.from_opt,
          "labelStepSize": labelStepSize |> Js.Undefined.from_opt,
          "max": max |> Js.Undefined.from_opt,
          "min": min |> Js.Undefined.from_opt,
          "onChange": onChange |> Js.Undefined.from_opt,
          "onRelease": onRelease |> Js.Undefined.from_opt,
          "renderLabel": renderLabel |> Js.Undefined.from_opt,
          "showTrackFill": showTrackFill |> unwrapBool,
          "stepSize": stepSize |> Js.Undefined.from_opt,
          "value": value |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module RangeSlider = {
  type t =
    Js.t {
      .
      className : Js.undefined string,
      disabled : Js.undefined Js.boolean,
      labelPrecision : Js.undefined int,
      labelStepSize : Js.undefined int,
      max : Js.undefined float,
      min : Js.undefined float,
      onChange : Js.undefined (float => unit),
      onRelease : Js.undefined (float => unit),
      renderLabel : Js.undefined RenderLabel.t,
      showTrackFill : Js.undefined Js.boolean,
      stepSize : Js.undefined int,
      value : Js.undefined float
    };
  external reactClass : ReasonReact.reactClass = "RangeSlider" [@@bs.module "@blueprintjs/core"];
  let make
      ::className=?
      ::disabled=?
      ::labelPrecision=?
      ::labelStepSize=?
      ::max=?
      ::min=?
      ::onChange=?
      ::onRelease=?
      ::renderLabel=?
      ::showTrackFill=?
      ::stepSize=?
      ::value=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "disabled": disabled |> unwrapBool,
          "labelPrecision": labelPrecision |> Js.Undefined.from_opt,
          "labelStepSize": labelStepSize |> Js.Undefined.from_opt,
          "max": max |> Js.Undefined.from_opt,
          "min": min |> Js.Undefined.from_opt,
          "onChange": onChange |> Js.Undefined.from_opt,
          "onRelease": onRelease |> Js.Undefined.from_opt,
          "renderLabel": renderLabel |> Js.Undefined.from_opt,
          "showTrackFill": showTrackFill |> unwrapBool,
          "stepSize": stepSize |> Js.Undefined.from_opt,
          "value": value |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module Tabs = {
  type t =
    Js.t {
      .
      animate : Js.undefined Js.boolean,
      className : Js.undefined string,
      defaultSelectedTabId : Js.undefined JsValue.t,
      id : JsValue.t,
      large : Js.undefined Js.boolean,
      onChange : Js.undefined (JsValue.t => JsValue.t => ReactEventRe.Mouse.t => unit),
      renderActiveTabPanelOnly : Js.undefined Js.boolean,
      selectedTabId : Js.undefined JsValue.t,
      vertical : Js.undefined Js.boolean
    };
  external reactClass : ReasonReact.reactClass = "Tabs2" [@@bs.module "@blueprintjs/core"];
  let make
      ::animate=?
      ::className=?
      ::defaultSelectedTabId=?
      ::id
      ::large
      ::onChange=?
      ::renderActiveTabPanelOnly=?
      ::selectedTabId=?
      ::vertical=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "animate": animate |> unwrapBool,
          "className": className |> Js.Undefined.from_opt,
          "defaultSelectedTabId": defaultSelectedTabId |> Js.Undefined.from_opt,
          "id": id,
          "large": large |> unwrapBool,
          "onChange": onChange |> Js.Undefined.from_opt,
          "renderActiveTabPanelOnly": renderActiveTabPanelOnly |> unwrapBool,
          "selectedTabId": selectedTabId |> Js.Undefined.from_opt,
          "vertical": vertical |> unwrapBool
        }: t
      )
      children;
};

module Tab = {
  type t =
    Js.t {
      .
      className : Js.undefined string,
      disabled : Js.undefined Js.boolean,
      id : JsValue.t,
      panel : Js.undefined ReasonReact.reactElement,
      title : Js.undefined ReasonReact.reactElement
    };
  external reactClass : ReasonReact.reactClass = "Tab2" [@@bs.module "@blueprintjs/core"];
  let make ::className=? ::disabled=? ::id ::panel=? ::title=? children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "disabled": disabled |> unwrapBool,
          "id": id,
          "panel": panel |> Js.Undefined.from_opt,
          "title": title |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module Tag = {
  type t =
    Js.t {
      .
      active : Js.undefined Js.boolean,
      className : Js.undefined string,
      intent : Js.undefined int,
      onRemove : Js.undefined (ReactEventRe.Mouse.t => t => unit)
    };
  external reactClass : ReasonReact.reactClass = "Tag" [@@bs.module "@blueprintjs/core"];
  let make ::active=? ::className=? ::intent=? ::onRemove=? children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "active": active |> unwrapBool,
          "className": className |> Js.Undefined.from_opt,
          "intent": intent |> Intent.fromOpt,
          "onRemove": onRemove |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module Text = {
  type t = Js.t {. className : Js.undefined string, ellipsize : Js.undefined Js.boolean};
  external reactClass : ReasonReact.reactClass = "Text" [@@bs.module "@blueprintjs/core"];
  let make ::className=? ::ellipsize=? children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {"className": className |> Js.Undefined.from_opt, "ellipsize": ellipsize |> unwrapBool}: t
      )
      children;
};

module Toaster = {
  type t =
    Js.t {
      .
      autoFocus : Js.undefined Js.boolean,
      canEscapeKeyClear : Js.undefined Js.boolean,
      className : Js.undefined string,
      inline : Js.undefined Js.boolean,
      position : Js.undefined Position.t
    };
  external reactClass : ReasonReact.reactClass = "Toaster" [@@bs.module "@blueprintjs/core"];
  /*
   TODO:
   http://blueprintjs.com/docs/#core/components/toast.static-method
   http://blueprintjs.com/docs/#core/components/toast.instance-methods
   */
  let make ::autoFocus=? ::canEscapeKeyClear=? ::className=? ::inline=? ::position=? children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "autoFocus": autoFocus |> unwrapBool,
          "canEscapeKeyClear": canEscapeKeyClear |> unwrapBool,
          "className": className |> Js.Undefined.from_opt,
          "inline": inline |> unwrapBool,
          "position": position |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module Toast = {
  type t =
    Js.t {
      .
      action : Js.undefined Js.Json.t, /* IActionProps & ILinkProps */
      className : Js.undefined string,
      iconName : Js.undefined string,
      intent : Js.undefined int,
      message : ReasonReact.reactElement,
      onDismiss : Js.undefined (Js.boolean => unit),
      timeout : Js.undefined int
    };
  external reactClass : ReasonReact.reactClass = "Toast" [@@bs.module "@blueprintjs/core"];
  let make
      ::action=?
      ::className=?
      ::iconName=?
      ::intent=?
      ::message
      ::onDismiss=?
      ::timeout=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "action": action |> Js.Undefined.from_opt,
          "className": className |> Js.Undefined.from_opt,
          "iconName": iconName |> Js.Undefined.from_opt,
          "intent": intent |> Intent.fromOpt,
          "message": message,
          "onDismiss": onDismiss |> Js.Undefined.from_opt,
          "timeout": timeout |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module Tooltip = {
  type t =
    Js.t {
      .
      className : Js.undefined string,
      content : Js.undefined ReasonReact.reactElement,
      defaultIsOpen : Js.undefined Js.boolean,
      hoverCloseDelay : Js.undefined int,
      hoverOpenDelay : Js.undefined int,
      inheritDarkTheme : Js.undefined Js.boolean,
      inline : Js.undefined Js.boolean,
      intent : Js.undefined int,
      isDisabled : Js.undefined Js.boolean,
      isOpen : Js.undefined Js.boolean,
      onInteraction : Js.undefined (Js.boolean => unit),
      openOnTargetFocus : Js.undefined Js.boolean,
      portalClassName : Js.undefined string,
      position : Js.undefined Position.t,
      rootElementTag : Js.undefined string,
      tetherOptions : Js.undefined Tether.t,
      tooltipClassName : Js.undefined string,
      transitionDuration : Js.undefined int,
      useSmartArrowPositioning : Js.undefined Js.boolean,
      useSmartPositioning : Js.undefined Js.boolean
    };
  external reactClass : ReasonReact.reactClass = "Tooltip" [@@bs.module "@blueprintjs/core"];
  let make
      ::className=?
      ::content=?
      ::defaultIsOpen=?
      ::hoverCloseDelay=?
      ::hoverOpenDelay=?
      ::inheritDarkTheme=?
      ::inline=?
      ::intent=?
      ::isDisabled=?
      ::isOpen=?
      ::onInteraction=?
      ::openOnTargetFocus=?
      ::portalClassName=?
      ::position=?
      ::rootElementTag=?
      ::tetherOptions=?
      ::tooltipClassName=?
      ::transitionDuration=?
      ::useSmartArrowPositioning=?
      ::useSmartPositioning=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "content": content |> Js.Undefined.from_opt,
          "defaultIsOpen": defaultIsOpen |> unwrapBool,
          "hoverCloseDelay": hoverCloseDelay |> Js.Undefined.from_opt,
          "hoverOpenDelay": hoverOpenDelay |> Js.Undefined.from_opt,
          "inheritDarkTheme": inheritDarkTheme |> unwrapBool,
          "inline": inline |> unwrapBool,
          "intent": intent |> Intent.fromOpt,
          "isDisabled": isDisabled |> unwrapBool,
          "isOpen": isOpen |> unwrapBool,
          "onInteraction": onInteraction |> Js.Undefined.from_opt,
          "openOnTargetFocus": openOnTargetFocus |> unwrapBool,
          "portalClassName": portalClassName |> Js.Undefined.from_opt,
          "position": position |> Js.Undefined.from_opt,
          "rootElementTag": rootElementTag |> Js.Undefined.from_opt,
          "tetherOptions": tetherOptions |> Js.Undefined.from_opt,
          "tooltipClassName": tooltipClassName |> Js.Undefined.from_opt,
          "transitionDuration": transitionDuration |> Js.Undefined.from_opt,
          "useSmartArrowPositioning": useSmartArrowPositioning |> unwrapBool,
          "useSmartPositioning": useSmartPositioning |> unwrapBool
        }: t
      )
      children;
};

module Tree = {
  module TreeNode = {
    type t = {
      childNodes: Js.undefined (Js.Array.t t),
      className: Js.undefined string,
      contentRef: Js.undefined (t => Dom.element => unit),
      depth: int,
      hasCaret: Js.undefined Js.boolean,
      iconName: Js.undefined string,
      id: JsValue.t,
      isExpanded: Js.undefined Js.boolean,
      isSelected: Js.undefined Js.boolean,
      key: Js.undefined JsValue.t,
      label: ReasonReact.reactElement,
      onClick: Js.undefined (t => ReactEventRe.Mouse.t => unit),
      onCollapse: Js.undefined (t => ReactEventRe.Mouse.t => unit),
      onContextMenu: Js.undefined (t => ReactEventRe.Mouse.t => unit),
      onDoubleClick: Js.undefined (t => ReactEventRe.Mouse.t => unit),
      onExpand: Js.undefined (t => ReactEventRe.Mouse.t => unit),
      path: Js.Array.t int,
      secondaryLabel: Js.undefined ReasonReact.reactElement
    };
  };
  type t =
    Js.t {
      .
      className : Js.undefined string,
      contents : Js.Array.t TreeNode.t,
      onNodeClick : Js.undefined (TreeNode.t => Js.Array.t int => ReactEventRe.Mouse.t => unit),
      onNodeCollapse : Js.undefined (TreeNode.t => Js.Array.t int => ReactEventRe.Mouse.t => unit),
      onNodeContextMenu :
        Js.undefined (TreeNode.t => Js.Array.t int => ReactEventRe.Mouse.t => unit),
      onNodeDoubleClick :
        Js.undefined (TreeNode.t => Js.Array.t int => ReactEventRe.Mouse.t => unit),
      onNodeExpand : Js.undefined (TreeNode.t => Js.Array.t int => ReactEventRe.Mouse.t => unit)
    };
  external reactClass : ReasonReact.reactClass = "Tree" [@@bs.module "@blueprintjs/core"];
  /*
   TODO
   http://blueprintjs.com/docs/#core/components/tree.instance-methods
   */
  let make
      ::className=?
      ::contents
      ::onNodeClick=?
      ::onNodeCollapse=?
      ::onNodeContextMenu=?
      ::onNodeDoubleClick=?
      ::onNodeExpand=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "contents": contents |> Array.of_list,
          "onNodeClick": onNodeClick |> Js.Undefined.from_opt,
          "onNodeCollapse": onNodeCollapse |> Js.Undefined.from_opt,
          "onNodeContextMenu": onNodeContextMenu |> Js.Undefined.from_opt,
          "onNodeDoubleClick": onNodeDoubleClick |> Js.Undefined.from_opt,
          "onNodeExpand": onNodeExpand |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module CollapsibleList = {
  type t =
    Js.t {
      .
      className : Js.undefined string,
      collapseFrom : Js.undefined int,
      dropdownProps : Js.undefined Popover.t,
      dropdownTarget : ReasonReact.reactElement,
      renderVisibleItem : MenuItem.t => int => ReasonReact.reactElement,
      visibleItemClassName : Js.undefined string,
      visibleItemCount : Js.undefined int
    };
  external reactClass : ReasonReact.reactClass =
    "CollapsibleList" [@@bs.module "@blueprintjs/core"];
  let make
      ::className=?
      ::collapseFrom=?
      ::dropdownProps=?
      ::dropdownTarget
      ::renderVisibleItem
      ::visibleItemClassName=?
      ::visibleItemCount=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "collapseFrom": collapseFrom |> Js.Undefined.from_opt,
          "dropdownProps": dropdownProps |> Js.Undefined.from_opt,
          "dropdownTarget": dropdownTarget,
          "renderVisibleItem": renderVisibleItem,
          "visibleItemClassName": visibleItemClassName |> Js.Undefined.from_opt,
          "visibleItemCount": visibleItemCount |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module Colors = {
  type t =
    | BLACK
    | BLUE1
    | BLUE2
    | BLUE3
    | BLUE4
    | BLUE5
    | COBALT1
    | COBALT2
    | COBALT3
    | COBALT4
    | COBALT5
    | DARK_GRAY1
    | DARK_GRAY2
    | DARK_GRAY3
    | DARK_GRAY4
    | DARK_GRAY5
    | FOREST1
    | FOREST2
    | FOREST3
    | FOREST4
    | FOREST5
    | GOLD1
    | GOLD2
    | GOLD3
    | GOLD4
    | GOLD5
    | GRAY1
    | GRAY2
    | GRAY3
    | GRAY4
    | GRAY5
    | GREEN1
    | GREEN2
    | GREEN3
    | GREEN4
    | GREEN5
    | INDIGO1
    | INDIGO2
    | INDIGO3
    | INDIGO4
    | INDIGO5
    | LIGHT_GRAY1
    | LIGHT_GRAY2
    | LIGHT_GRAY3
    | LIGHT_GRAY4
    | LIGHT_GRAY5
    | LIME1
    | LIME2
    | LIME3
    | LIME4
    | LIME5
    | ORANGE1
    | ORANGE2
    | ORANGE3
    | ORANGE4
    | ORANGE5
    | RED1
    | RED2
    | RED3
    | RED4
    | RED5
    | ROSE1
    | ROSE2
    | ROSE3
    | ROSE4
    | ROSE5
    | SEPIA1
    | SEPIA2
    | SEPIA3
    | SEPIA4
    | SEPIA5
    | TURQUOISE1
    | TURQUOISE2
    | TURQUOISE3
    | TURQUOISE4
    | TURQUOISE5
    | VERMILION1
    | VERMILION2
    | VERMILION3
    | VERMILION4
    | VERMILION5
    | VIOLET1
    | VIOLET2
    | VIOLET3
    | VIOLET4
    | VIOLET5
    | WHITE;
  let toHex c =>
    switch c {
    | BLACK => "#10161A"
    | BLUE1 => "#0E5A8A"
    | BLUE2 => "#106BA3"
    | BLUE3 => "#137CBD"
    | BLUE4 => "#2B95D6"
    | BLUE5 => "#48AFF0"
    | COBALT1 => "#1F4B99"
    | COBALT2 => "#2458B3"
    | COBALT3 => "#2965CC"
    | COBALT4 => "#4580E6"
    | COBALT5 => "#669EFF"
    | DARK_GRAY1 => "#182026"
    | DARK_GRAY2 => "#202B33"
    | DARK_GRAY3 => "#293742"
    | DARK_GRAY4 => "#30404D"
    | DARK_GRAY5 => "#394B59"
    | FOREST1 => "#1D7324"
    | FOREST2 => "#238C2C"
    | FOREST3 => "#29A634"
    | FOREST4 => "#43BF4D"
    | FOREST5 => "#62D96B"
    | GOLD1 => "#A67908"
    | GOLD2 => "#BF8C0A"
    | GOLD3 => "#D99E0B"
    | GOLD4 => "#F2B824"
    | GOLD5 => "#FFC940"
    | GRAY1 => "#5C7080"
    | GRAY2 => "#738694"
    | GRAY3 => "#8A9BA8"
    | GRAY4 => "#A7B6C2"
    | GRAY5 => "#BFCCD6"
    | GREEN1 => "#0A6640"
    | GREEN2 => "#0D8050"
    | GREEN3 => "#0F9960"
    | GREEN4 => "#15B371"
    | GREEN5 => "#3DCC91"
    | INDIGO1 => "#5642A6"
    | INDIGO2 => "#634DBF"
    | INDIGO3 => "#7157D9"
    | INDIGO4 => "#9179F2"
    | INDIGO5 => "#AD99FF"
    | LIGHT_GRAY1 => "#CED9E0"
    | LIGHT_GRAY2 => "#D8E1E8"
    | LIGHT_GRAY3 => "#E1E8ED"
    | LIGHT_GRAY4 => "#EBF1F5"
    | LIGHT_GRAY5 => "#F5F8FA"
    | LIME1 => "#728C23"
    | LIME2 => "#87A629"
    | LIME3 => "#9BBF30"
    | LIME4 => "#B6D94C"
    | LIME5 => "#D1F26D"
    | ORANGE1 => "#A66321"
    | ORANGE2 => "#BF7326"
    | ORANGE3 => "#D9822B"
    | ORANGE4 => "#F29D49"
    | ORANGE5 => "#FFB366"
    | RED1 => "#A82A2A"
    | RED2 => "#C23030"
    | RED3 => "#DB3737"
    | RED4 => "#F55656"
    | RED5 => "#FF7373"
    | ROSE1 => "#A82255"
    | ROSE2 => "#C22762"
    | ROSE3 => "#DB2C6F"
    | ROSE4 => "#F5498B"
    | ROSE5 => "#FF66A1"
    | SEPIA1 => "#63411E"
    | SEPIA2 => "#7D5125"
    | SEPIA3 => "#96622D"
    | SEPIA4 => "#B07B46"
    | SEPIA5 => "#C99765"
    | TURQUOISE1 => "#008075"
    | TURQUOISE2 => "#00998C"
    | TURQUOISE3 => "#00B3A4"
    | TURQUOISE4 => "#14CCBD"
    | TURQUOISE5 => "#2EE6D6"
    | VERMILION1 => "#9E2B0E"
    | VERMILION2 => "#B83211"
    | VERMILION3 => "#D13913"
    | VERMILION4 => "#EB532D"
    | VERMILION5 => "#FF6E4A"
    | VIOLET1 => "#5C255C"
    | VIOLET2 => "#752F75"
    | VIOLET3 => "#8F398F"
    | VIOLET4 => "#A854A8"
    | VIOLET5 => "#C274C2"
    | WHITE => "#FFFFFF"
    };
};

module Keys = {
  type t =
    | BACKSPACE
    | TAB
    | ENTER
    | SHIFT
    | ESCAPE
    | SPACE
    | ARROW_LEFT
    | ARROW_UP
    | ARROW_RIGHT
    | ARROW_DOWN
    | DELETE;
  let toInt x =>
    switch x {
    | BACKSPACE => 8
    | TAB => 9
    | ENTER => 13
    | SHIFT => 16
    | ESCAPE => 27
    | SPACE => 32
    | ARROW_LEFT => 37
    | ARROW_UP => 38
    | ARROW_RIGHT => 39
    | ARROW_DOWN => 40
    | DELETE => 46
    };
};

module Classes = {
  type t =
    | DARK
    | ACTIVE
    | MINIMAL
    | DISABLED
    | SMALL
    | LARGE
    | LOADING
    | INTERACTIVE
    | ALIGN_LEFT
    | ALIGN_RIGHT
    | INLINE
    | FILL
    | FIXED
    | FIXED_TOP
    | VERTICAL
    | ROUND
    | TEXT_MUTED
    | TEXT_OVERFLOW_ELLIPSIS
    | UI_TEXT_LARGE
    | ALERT
    | ALERT_BODY
    | ALERT_CONTENTS
    | ALERT_FOOTER
    | BREADCRUMB
    | BREADCRUMB_CURRENT
    | BREADCRUMBS
    | BREADCRUMBS_COLLAPSED
    | BUTTON
    | BUTTON_GROUP
    | CALLOUT
    | CARD
    | COLLAPSE
    | COLLAPSIBLE_LIST
    | CONTEXT_MENU
    | CONTEXT_MENU_POPOVER_TARGET
    | CONTROL
    | CONTROL_GROUP
    | CONTROL_INDICATOR
    | DIALOG
    | DIALOG_CONTAINER
    | DIALOG_BODY
    | DIALOG_CLOSE_BUTTON
    | DIALOG_FOOTER
    | DIALOG_FOOTER_ACTIONS
    | DIALOG_HEADER
    | EDITABLE_TEXT
    | ELEVATION_0
    | ELEVATION_1
    | ELEVATION_2
    | ELEVATION_3
    | ELEVATION_4
    | INPUT
    | INPUT_GROUP
    | CHECKBOX
    | RADIO
    | SWITCH
    | FILE_UPLOAD
    | FILE_UPLOAD_INPUT
    | INTENT_PRIMARY
    | INTENT_SUCCESS
    | INTENT_WARNING
    | INTENT_DANGER
    | LABEL
    | FORM_GROUP
    | FORM_CONTENT
    | FORM_HELPER_TEXT
    | MENU
    | MENU_ITEM
    | MENU_ITEM_LABEL
    | MENU_SUBMENU
    | MENU_DIVIDER
    | MENU_HEADER
    | NAVBAR
    | NAVBAR_GROUP
    | NAVBAR_HEADING
    | NAVBAR_DIVIDER
    | NON_IDEAL_STATE
    | NON_IDEAL_STATE_ACTION
    | NON_IDEAL_STATE_DESCRIPTION
    | NON_IDEAL_STATE_ICON
    | NON_IDEAL_STATE_TITLE
    | NON_IDEAL_STATE_VISUAL
    | NUMERIC_INPUT
    | OVERLAY
    | OVERLAY_BACKDROP
    | OVERLAY_CONTENT
    | OVERLAY_INLINE
    | OVERLAY_OPEN
    | OVERLAY_SCROLL_CONTAINER
    | POPOVER
    | POPOVER_ARROW
    | POPOVER_BACKDROP
    | POPOVER_CONTENT
    | POPOVER_DISMISS
    | POPOVER_DISMISS_OVERRIDE
    | POPOVER_OPEN
    | POPOVER_TARGET
    | TRANSITION_CONTAINER
    | PROGRESS_BAR
    | PROGRESS_METER
    | PROGRESS_NO_STRIPES
    | PROGRESS_NO_ANIMATION
    | PORTAL
    | SELECT
    | SKELETON
    | SLIDER
    | SLIDER_HANDLE
    | SLIDER_LABEL
    | RANGE_SLIDER
    | SPINNER
    | SVG_SPINNER
    | TAB
    | TAB_LIST
    | TAB_PANEL
    | TABS
    | TABLE
    | TABLE_CONDENSED
    | TABLE_STRIPED
    | TABLE_BORDERED
    | TAG
    | TAG_REMOVABLE
    | TAG_REMOVE
    | TOAST
    | TOAST_CONTAINER
    | TOAST_MESSAGE
    | TOOLTIP
    | TREE
    | TREE_NODE
    | TREE_NODE_CARET
    | TREE_NODE_CARET_CLOSED
    | TREE_NODE_CARET_NONE
    | TREE_NODE_CARET_OPEN
    | TREE_NODE_CONTENT
    | TREE_NODE_EXPANDED
    | TREE_NODE_ICON
    | TREE_NODE_LABEL
    | TREE_NODE_LIST
    | TREE_NODE_SECONDARY_LABEL
    | TREE_NODE_SELECTED
    | TREE_ROOT
    | ICON
    | ICON_STANDARD
    | ICON_LARGE;
  let toString c =>
    switch c {
    | DARK => "pt-dark"
    | ACTIVE => "pt-active"
    | MINIMAL => "pt-minimal"
    | DISABLED => "pt-disabled"
    | SMALL => "pt-small"
    | LARGE => "pt-large"
    | LOADING => "pt-loading"
    | INTERACTIVE => "pt-interactive"
    | ALIGN_LEFT => "pt-align-left"
    | ALIGN_RIGHT => "pt-align-right"
    | INLINE => "pt-inline"
    | FILL => "pt-fill"
    | FIXED => "pt-fixed"
    | FIXED_TOP => "pt-fixed-top"
    | VERTICAL => "pt-vertical"
    | ROUND => "pt-round"
    | TEXT_MUTED => "pt-text-muted"
    | TEXT_OVERFLOW_ELLIPSIS => "pt-text-overflow-ellipsis"
    | UI_TEXT_LARGE => "pt-ui-text-large"
    | ALERT => "pt-alert"
    | ALERT_BODY => "pt-alert-body"
    | ALERT_CONTENTS => "pt-alert-contents"
    | ALERT_FOOTER => "pt-alert-footer"
    | BREADCRUMB => "pt-breadcrumb"
    | BREADCRUMB_CURRENT => "pt-breadcrumb-current"
    | BREADCRUMBS => "pt-breadcrumbs"
    | BREADCRUMBS_COLLAPSED => "pt-breadcrumbs-collapsed"
    | BUTTON => "pt-button"
    | BUTTON_GROUP => "pt-button-group"
    | CALLOUT => "pt-callout"
    | CARD => "pt-card"
    | COLLAPSE => "pt-collapse"
    | COLLAPSIBLE_LIST => "pt-collapse-list"
    | CONTEXT_MENU => "pt-context-menu"
    | CONTEXT_MENU_POPOVER_TARGET => "pt-context-menu-popover-target"
    | CONTROL => "pt-control"
    | CONTROL_GROUP => "pt-control-group"
    | CONTROL_INDICATOR => "pt-control-indicator"
    | DIALOG => "pt-dialog"
    | DIALOG_CONTAINER => "pt-dialog-container"
    | DIALOG_BODY => "pt-dialog-body"
    | DIALOG_CLOSE_BUTTON => "pt-dialog-close-button"
    | DIALOG_FOOTER => "pt-dialog-footer"
    | DIALOG_FOOTER_ACTIONS => "pt-dialog-footer-actions"
    | DIALOG_HEADER => "pt-dialog-header"
    | EDITABLE_TEXT => "pt-editable-text"
    | ELEVATION_0 => "pt-elevation-0"
    | ELEVATION_1 => "pt-elevation-1"
    | ELEVATION_2 => "pt-elevation-2"
    | ELEVATION_3 => "pt-elevation-3"
    | ELEVATION_4 => "pt-elevation-4"
    | INPUT => "pt-input"
    | INPUT_GROUP => "pt-input-group"
    | CHECKBOX => "pt-checkbox"
    | RADIO => "pt-radio"
    | SWITCH => "pt-switch"
    | FILE_UPLOAD => "pt-file-upload"
    | FILE_UPLOAD_INPUT => "pt-file-upload-input"
    | INTENT_PRIMARY => "pt-intent-primary"
    | INTENT_SUCCESS => "pt-intent-success"
    | INTENT_WARNING => "pt-intent-warning"
    | INTENT_DANGER => "pt-intent-danger"
    | LABEL => "pt-label"
    | FORM_GROUP => "pt-form-group"
    | FORM_CONTENT => "pt-form-content"
    | FORM_HELPER_TEXT => "pt-form-helper-text"
    | MENU => "pt-menu"
    | MENU_ITEM => "pt-menu-item"
    | MENU_ITEM_LABEL => "pt-menu-item-label"
    | MENU_SUBMENU => "pt-submenu"
    | MENU_DIVIDER => "pt-menu-divider"
    | MENU_HEADER => "pt-menu-header"
    | NAVBAR => "pt-navbar"
    | NAVBAR_GROUP => "pt-navbar-group"
    | NAVBAR_HEADING => "pt-navbar-heading"
    | NAVBAR_DIVIDER => "pt-navbar-divider"
    | NON_IDEAL_STATE => "pt-non-ideal-state"
    | NON_IDEAL_STATE_ACTION => "pt-non-ideal-state-action"
    | NON_IDEAL_STATE_DESCRIPTION => "pt-non-ideal-state-description"
    | NON_IDEAL_STATE_ICON => "pt-non-ideal-state-icon"
    | NON_IDEAL_STATE_TITLE => "pt-non-ideal-state-title"
    | NON_IDEAL_STATE_VISUAL => "pt-non-ideal-state-visual"
    | NUMERIC_INPUT => "pt-numeric-input"
    | OVERLAY => "pt-overlay"
    | OVERLAY_BACKDROP => "pt-overlay-backdrop"
    | OVERLAY_CONTENT => "pt-overlay-content"
    | OVERLAY_INLINE => "pt-overlay-inline"
    | OVERLAY_OPEN => "pt-overlay-open"
    | OVERLAY_SCROLL_CONTAINER => "pt-overlay-scroll-container"
    | POPOVER => "pt-popover"
    | POPOVER_ARROW => "pt-popover-arrow"
    | POPOVER_BACKDROP => "pt-popover-backdrop"
    | POPOVER_CONTENT => "pt-popover-content"
    | POPOVER_DISMISS => "pt-popover-dismiss"
    | POPOVER_DISMISS_OVERRIDE => "pt-popover-dismiss-override"
    | POPOVER_OPEN => "pt-popover-open"
    | POPOVER_TARGET => "pt-popover-target"
    | TRANSITION_CONTAINER => "pt-transition-container"
    | PROGRESS_BAR => "pt-progress-bar"
    | PROGRESS_METER => "pt-progress-meter"
    | PROGRESS_NO_STRIPES => "pt-no-stripes"
    | PROGRESS_NO_ANIMATION => "pt-no-animation"
    | PORTAL => "pt-portal"
    | SELECT => "pt-select"
    | SKELETON => "pt-skeleton"
    | SLIDER => "pt-slider"
    | SLIDER_HANDLE => "pt-slider-handle"
    | SLIDER_LABEL => "pt-slider-label"
    | RANGE_SLIDER => "pt-range-slider"
    | SPINNER => "pt-spinner"
    | SVG_SPINNER => "pt-svg-spinner"
    | TAB => "pt-tab"
    | TAB_LIST => "pt-tab-list"
    | TAB_PANEL => "pt-tab-panel"
    | TABS => "pt-tabs"
    | TABLE => "pt-table"
    | TABLE_CONDENSED => "pt-condensed"
    | TABLE_STRIPED => "pt-striped"
    | TABLE_BORDERED => "pt-bordered"
    | TAG => "pt-tag"
    | TAG_REMOVABLE => "pt-tag-removable"
    | TAG_REMOVE => "pt-tag-remove"
    | TOAST => "pt-toast"
    | TOAST_CONTAINER => "pt-toast-container"
    | TOAST_MESSAGE => "pt-toast-message"
    | TOOLTIP => "pt-tooltip"
    | TREE => "pt-tree"
    | TREE_NODE => "pt-tree-node"
    | TREE_NODE_CARET => "pt-tree-node-caret"
    | TREE_NODE_CARET_CLOSED => "pt-tree-node-caret-closed"
    | TREE_NODE_CARET_NONE => "pt-tree-node-caret-none"
    | TREE_NODE_CARET_OPEN => "pt-tree-node-caret-open"
    | TREE_NODE_CONTENT => "pt-tree-node-content"
    | TREE_NODE_EXPANDED => "pt-tree-node-expanded"
    | TREE_NODE_ICON => "pt-tree-node-icon"
    | TREE_NODE_LABEL => "pt-tree-node-label"
    | TREE_NODE_LIST => "pt-tree-node-list"
    | TREE_NODE_SECONDARY_LABEL => "pt-tree-node-secondary-label"
    | TREE_NODE_SELECTED => "pt-tree-node-selected"
    | TREE_ROOT => "pt-tree-root"
    | ICON => "pt-icon"
    | ICON_STANDARD => "pt-icon-standard"
    | ICON_LARGE => "pt-icon-large"
    };
  external iconClass : string => string = "iconClass" [@@bs.module "@blueprintjs/core"];
  let iconClass css_class => iconClass (toString css_class);
  external intentClass : int => string = "intentClass" [@@bs.module "@blueprintjs/core"];
  let intentClass intent => intentClass (Intent.toInt intent);
};