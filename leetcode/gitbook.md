> gitbook init
>
> gitbook build
>
> gitbook serve

[cols="~,~,60"]

[cols="~,~,60"]

[options="autowidth"]

|===
|Path|Type|Description

|`+access_token+`
|`+String+`
|The access token issued by authentication and authorization server

|`+token_type+`
|`+String+`
|The type of the token

|`+refresh_token+`
|`+String+`
|The refresh token which can be used to obtain new access tokens

|`+expires_in+`
|`+Number+`
|The lifetime in seconds of the access token.

|`+scope+`
|`+String+`
|The scope of the access token

|`+jti+`
|`+String+`
|JWT id

|`+tenant+`
|`+String+`
|Tenant name

|===

- - Initialize \text{left}left pointer to 0 and \text{right}right pointer to size-1

  - While

     

    \text{left}< \text{right}left<right

    , do:

    - If

       

      \text{height[left]}height[left]

       

      is smaller than

       

      \text{height[right]}height[right]

      - If \text{height[left]} \geq \text{left\_max}height[left]≥left_max, update \text{left\_max}left_max
      - Else add \text{left\_max}-\text{height[left]}left_max−height[left] to \text{ans}ans
      - Add 1 to \text{left}left.