# bs-blueprintjs

**Note**: these are **bindings** to the [Blueprint.js](https://github.com/palantir/blueprint) UI toolkit. These are a thin typed wrapper to let you use Blueprintjs Components in bucklescript.

## Documentation

Example usage:

```reason
let component = ReasonReact.statelessComponent "App";

let make ::message _children => {
  ...component,
  render: fun _self =>
    <div className="App">
        <Blueprintjs.Button
          text="Click"
          rightIconName="search"
          disabled=false
          intent=Blueprintjs.Intent.PRIMARY
          onClick=(fun evt => Js.log evt)
        />
    </div>
};
```